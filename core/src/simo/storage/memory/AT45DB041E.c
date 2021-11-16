/**
 * @file AT45DB041E.c
 * @author Velardez German (gvelardez@inti.gob.ar)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "simo/storage/memory/AT45DB041E.h"
#include "hardware/gpio.h"
#include "time.h"
#include <stdint.h>

#include "pico/stdlib.h"

#include  <stdlib.h>





//bits de estado

#define AT45DB_TIMEOUT          1000

#define AT45DB_STATUS_PGSIZE  (1 << 0) /* PAGE SIZE */
#define AT45DB_STATUS_PROTECT (1 << 1) /* PROTECT */
#define AT45DB_STATUS_COMP    (1 << 6) /* COMP */
#define AT45DB_STATUS_READY   (1 << 7) /* RDY/BUSY */
 

//comandos y secuencias

#define ERASE_SECUENCE		        0xC7, 0x94, 0x80, 0x9A     //secuencia de borrado del chip completo
#define ERASE_SECUENCE_LEN          4                           
#define RESUME_CMD                  0xAB                      //salgo del deep sleep_us
#define GETSTATUS_CMD               0xD7                      //Leo los registros de estado de la memoria

#define WRITE_WITH_BUFF1            0x82                     // usar buffer 1 para escribir en memoria

#define AT45DB_PG_SIZE_256_SECUENCE    0x3D, 0x2A, 0x80, 0xA6    //Programa tamaño de pagina en 256
#define AT45DB_PG_SIZE_256_LEN          4

#define AT45DB_PG_SIZE_264_SECUENCE     0x3D, 0x2A, 0x80 ,0xA7    //Programa tamaño de pagina en 264
#define AT45DB_PG_SIZE_264_LEN          4









// Secuencia de ID product

#define GET_ID_CMD                0x9F
#define MANUFACTURER_ID           0x1F    //id byte  1
#define DEVICE_ID_1               0x24    //id byte  2
#define DEVICE_ID_2               0x00    //id byte  3
#define EDI                       0x01    // id byte 4








// escribir en memoria
// !Escribir en memoria principal mediante buffer 1. 
// !Direccion : pagina[15bits] | posicion dentro del buffer[8]
#define WRITE_BUFF1_CMD                    0x82    
#define WRITE_BUFF2_CMD                    0x85    // Escribir en memoria principal mediante buffer 2
#define CMD_FAST_READ                     (0x0B) // max speed 85 MHz. Also its posible to use 0x1B


/* Programacion del tamaño de pagina */

static  uint8_t at45db_pgsize_256_cmd[] = {  AT45DB_PG_SIZE_256_SECUENCE    };
static  uint8_t at45db_pgsize_264_cmd[] = {  AT45DB_PG_SIZE_264_SECUENCE    };


/* Secuencia de borrado de todo el chip*/
static  uint8_t erase_cmd[ERASE_SECUENCE_LEN] = {ERASE_SECUENCE};



/*****************************************************************************/
/*Status Register Format:                                   */
/* ------------------------------------------------------------------------- */
/* | bit7   | bit6   | bit5   | bit4   | bit3   | bit2   | bit1   | bit0   | */
/* |--------|--------|--------|--------|--------|--------|--------|--------| */
/* |RDY/BUSY| COMP   |         device density            |   X    |   X    | */
/* ------------------------------------------------------------------------- */
/* 0:busy   |        |        AT45DB041:0111             | protect|page size */
/* 1:ready  |        |        AT45DB161:1011             |                   */
/* --------------------------------------------------------------------------*/


/**
 *  Memoria utilizada: at45db041E
 * PAGINAS: 2048        DIRECCION DE 11 BITS
 * BLOQUES: 256         DIRECCION DE 8 BITS
 * SECTORES: 8          
 * 
 * Se pueden usar paginas de 264bytes o de 256bytes. 
 * cmd escribir | 3bytes de direccion(  11 bits pagina (0 a 2048| 8 bytes posicion de la pagina | 5 dummy bits)
 * **/
#define PAGE_OFFSET         13
#define POS_OFFSET          5
#define BLOCK_OFFSET        



//Prototipos
static inline void  __at45db_start(AT45DB041E_t* mem);

static inline uint8_t __at45db_get_status(AT45DB041E_t* mem);

static inline bool  __at45db_check_id(AT45DB041E_t* mem);

static inline uint8_t __at45_is_bussy(AT45DB041E_t* mem);





/**
 * @brief  Secuencia de inicio de la memoria.
 * 
 * @param mem 
 * @return ** void 
 */
static inline void  __at45db_start(AT45DB041E_t* mem)
{

     // CS DE ALTO A BAJO  (INICIO DE COMANDO)

    gpio_put(mem->cs_pin, 1);  //flanco ascendente
    gpio_put(mem->cs_pin, 0);  //flanco descendente

    //Despierto el micro en caso de deep sleep_us
    simo_spi_write(mem->spi,(uint8_t*)RESUME_CMD,1);

    gpio_put(mem->cs_pin, 1);  //flanco ascendente

    //obtengo el id del producto
    if(!__at45db_check_id(mem)) return ;
    
    //configuro tamaño de pagina y buffer: 256

    if(!(__at45_is_bussy(mem) & AT45DB_STATUS_PGSIZE)) 
    //pregunto si page_size es 264. Si es true, configuro en 256
    {
    
        gpio_put(mem->cs_pin, 0);  //flanco descendente

        simo_spi_write(mem->spi,(uint8_t*)at45db_pgsize_256_cmd,AT45DB_PG_SIZE_264_LEN);

        gpio_put(mem->cs_pin, 1);  //flanco ascendente
    }
}

/**
 * @brief 
 *  Checkeo que la memoria sea espeficicamente el modelo AT45DB041E. 
 *  En caso de utilizar otra memoria se deben modificar parametros en el checkeo
 * @param mem 
 * @return true 
 * @return false 
 */
static inline bool  __at45db_check_id(AT45DB041E_t* mem)
{
   
 //envio comando para obtener product ID

    uint8_t cmd[5]=
    {
        GET_ID_CMD,
        0,
        0,
        0,
        0
    };

// buffer para datos
    uint8_t  data[5]=
    {
        0, //dummy
        0,
        0,
        0,
        0
    };

  
  
     //en alto el CS Pin
    gpio_put(mem->cs_pin,0 );  //flanco ascendente
    simo_spi_write_read(mem->spi,cmd,data,5);    //leo el primer byte del registro estado
    //en alto el CS Pin
    gpio_put(mem->cs_pin, 1);  //flanco ascendente

   // sleep_us(1);

    //checkeo respuesta correcta
    if( data[1] != MANUFACTURER_ID    
        || data[2] != DEVICE_ID_1        
        || data[3] != DEVICE_ID_2        
        || data[4] != EDI) 
    {
        return false;  //fallo checkeo de ID
    }
        return true;
}


/**
 * @brief 
 *   Retorna el primer byte de estatus del chip
 * @param mem 
 * @return ** uint8_t 
 */
static inline uint8_t __at45db_get_status(AT45DB041E_t* mem)
{
    uint8_t cmd[2]={GETSTATUS_CMD,0};
    uint8_t status[2]={0,0};

            //flanco ascendente 
     //en alto el CS Pin
    gpio_put(mem->cs_pin,0 );           //flanco ascendente
    simo_spi_write_read(mem->spi,cmd,status,2);    //leo el primer byte del registro estado

     //en alto el CS Pin
    gpio_put(mem->cs_pin, 1);  //flanco ascendente
    return  status[1];
}
/**
 * @brief  Espero que la memoria este disponible y retorno el primer byte de status
 * 
 * @param mem  objeto memoria
 * @return ** uint8_t 
 */
static inline uint8_t __at45_is_bussy(AT45DB041E_t* mem)
{
    uint8_t sr;

    uint32_t counter= 0;
    while(!((sr =__at45db_get_status(mem)) & AT45DB_STATUS_READY) || (counter <= AT45DB_TIMEOUT))  //mientras este ocupado, espere
    {
        sleep_us(1);
        counter+=1;
    }
    return sr;  //es el primer byte del registro de estados
}





AT45DB041E_t* simo_AT45DB041E_create(spi_t spi, uint32_t cs_pin,uint32_t freq)
{
    AT45DB041E_t* _mem =(AT45DB041E_t*) malloc (sizeof(AT45DB041E_t));
    if(_mem == NULL) return NULL;   // fallo en asignar memoria a objeto
    _mem->cs_pin = cs_pin;
    _mem-> freq= freq;
    _mem->spi = spi;
    _mem->spi_ready = false;

    return _mem;

}


void simo_AT45DB041E_delete(AT45DB041E_t* mem)
{
    if(mem != NULL)
    {
        free(mem);
    }
}


bool simo_AT45DB041E_init(AT45DB041E_t* mem)
{
    if(mem != NULL)
    {
        // inicio SPI
        simo_spi_init(mem->spi,mem->freq);
        // configuro gpio CS
        gpio_init(mem->cs_pin);
        gpio_set_dir(mem->cs_pin, 1);
        gpio_put(mem->cs_pin, 1);  //flanco ascendente. Dejo el PIN en alto


        mem->spi_ready = true;
    }
}

bool simo_AT45DB041E_deinit(AT45DB041E_t* mem)
{
    if(mem != NULL)
    {
        //deinicio SPI
        simo_spi_deinit(mem->spi);
        // desconfiguro gpio CS
       //  gpio_init(mem->cs_pin);
       // gpio_set_dir(mem->cs_pin, 1);
        gpio_put(mem->cs_pin, 0);  //flanco ascendente. Dejo el PIN en alto


        mem->spi_ready = false;
    }
}




void simo_AT45DB041E_full_erase(AT45DB041E_t* mem)
{

    // CS DE ALTO A BAJO  (INICIO DE COMANDO)
    gpio_put(mem->cs_pin, 0);  //flanco descendente
    
    simo_spi_write(mem->spi,erase_cmd,ERASE_SECUENCE_LEN);
    
    //CD DE BAJO A ALTO (FIN DE COMANDO)
    gpio_put(mem->cs_pin, 1);  //flanco ascendente

}



void simo_AT45DB041E_save_data(AT45DB041E_t* mem,
                                 uint8_t* buffer,
                                 uint32_t buffer_len,
                                 uint16_t page,
                                 uint16_t position_page)
{


    // cmd escribir | 3bytes de direccion(  15 bits pagina (0 a 2048| 8 bytes posicion de la pagina | 5 dummy bits)

    uint32_t _page = (uint32_t) (page << PAGE_OFFSET);
    uint32_t _pos = (uint32_t)  (position_page << POS_OFFSET);
    uint32_t address = (uint32_t)  _page | _pos;
    
    uint8_t cmd[4] ;    
      

    cmd[0] = WRITE_BUFF1_CMD;
    cmd[1] = (address >> 24)  & 0xff;
    cmd[2] = (address >> 16)  & 0xff;
    cmd[3] = (address >> 8)& 0xff;

    //inicia (pulso en bajo)

    gpio_put(mem->cs_pin, 0); 
   
    simo_spi_write(mem->spi,cmd,4);   // envio comandos

    
    simo_spi_write(mem->spi,buffer,(uint32_t)buffer_len); // escribo en memoria
    // finaliza (pulso en alto)
    gpio_put(mem->cs_pin, 1); 

     __at45_is_bussy(mem);

}



void simo_AT45DB041E_read_data(AT45DB041E_t* mem,
                                uint8_t* buffer,
                                uint32_t buffer_len,
                                uint16_t page,
                                uint16_t position_page)
{

    // cmd escribir | 3bytes de direccion(  11 bits pagina (0 a 2048| 8 bytes posicion de la pagina | 5 dummy bits)

    uint32_t _page = (uint32_t) (page << PAGE_OFFSET);
    uint32_t _pos = (uint32_t)  (position_page << POS_OFFSET);
    uint32_t address = (uint32_t)  _page | _pos;
    uint8_t cmd[5] ;    
      
    cmd[0] = CMD_FAST_READ;
    cmd[1] = (address >> 24) & 0xff;
    cmd[2] = (address >> 16) & 0xff;
    cmd[3] = (address >> 8)  & 0xff;
    cmd[4] = 0;
    //inicia (pulso en bajo)

    gpio_put(mem->cs_pin, 0); 
    
    
    simo_spi_write(mem->spi,cmd,5);    //  Envio secuencia de commandos

    simo_spi_read(mem->spi,buffer,0,buffer_len);    //buffer a escribir
    // finaliza (pulso en alto)
    gpio_put(mem->cs_pin, 1); 

     __at45_is_bussy(mem);

}
