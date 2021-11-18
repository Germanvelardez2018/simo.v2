/**
 * @file memory_store.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion de driver para el manejor del almacenamiento externo (NIVEL 1).Depende de SIMO SPI
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "simo/storage/memory_store.h"
#include "simo/storage/memory/AT45DB041E.h"
#include "simo/hardware/spi.h"
#include "pico/time.h"
#include  <stdio.h>
#include <string.h>
#include <stdlib.h> 
/*
 *  Memoria utilizada: at45db041E
 * PAGINAS: 2048        DIRECCION DE 11 BITS
 * BLOQUES: 256         DIRECCION DE 8 BITS
 * SECTORES: 8  
*/
#define N_PAGES                 2048   // Cantidad de paginas(256bytes disponibles)
#define SIZE_PAGE               256     //Tamanio en bytes de las paginas
#define ADDRES_COUNTER          10     //Direccion donde se encuentra el contador de datos

#define DATA_OFFSET             48   //2000 DATOS PARA ALMACENAR
#define MAX_DATA                2000

#define CHAR_INIT_SIMO          0x11  //Si no se detecta este caracter el string es invalido y se descarta
#define MAX_LEN_STRING          254  // Tamanio maximo de los string a almacenar




// variable privada de memoria a utilizar

static AT45DB041E_t* _memory_app;
#define SPI_APP             SIMO_SPI1  //! Utilizo el SPI1
#define CS_PIN              9          //! El chip select utilizado sera el pin 9
#define MEMORY_APP_BAUDRATE_FAST       (50*100000) //5 MHz
#define MEMORY_APP_BAUDRATE_LOW        (10*10000) //1 MHz
#define FREQ_APP            MEMORY_APP_BAUDRATE_LOW











/**
 * @brief Formato de Frames guardados.
 * Tamanio: 255 (una pagina)
 * 
 *  primer byte = CHAR_INIT_SIMO| segundo  byte tamanio utilizados  | string ( array de char)(254 max) |
 * 
 */

/**
 * @brief  Devuelve un buffer con el mensaje mas 2 bytes de cabecera. 
 * Luego de usar el buffer se debe liberar la memoria del mismo
 * 
 * @param msg   Cadena con el mensaje. Debe tener \0 en el final
 * @param buffer_static    de 256 bytes    
 * @return ** char* 
 */


static void  add_simo_format(char const* msg, char* buffer_static)
{
    uint8_t len = strlen(msg)+1;

    buffer_static[0]= CHAR_INIT_SIMO;               //primer byte en todas las paginas con datos utiles
    buffer_static[1]= len ;    //tamanio del buffer
    memcpy(&(buffer_static[2]),msg,len);

}

   





 // counter ----|PARTE ALTA[addres = 1]| PARTE BAJA[addres = 0]

 //               buffer[0] == parte baja | buffer[1] = prte alta
 

static uint16_t _get_counter()
{
    uint8_t counter[2]={0};

    simo_AT45DB041E_read_data(_memory_app,counter,2,ADDRES_COUNTER,0);

    uint16_t ret = (uint16_t)(counter[0]) | (uint16_t)(counter[1]<< 8) ;  // 
    return ret ;
}




static void _set_counter(uint16_t count)
{
    uint8_t buffer[2];
    buffer[1] = (uint8_t) count >>8; // 
    buffer[0] = (uint8_t) count ;   // 
    simo_AT45DB041E_save_data(_memory_app,(uint8_t*)buffer,2,ADDRES_COUNTER,0);
}

bool simo_memory_store_init(void)
{
    bool ret = false;
    _memory_app = simo_AT45DB041E_create(SPI_APP,CS_PIN,FREQ_APP);

    if( _memory_app  != NULL)
    {
       ret =  simo_AT45DB041E_init(_memory_app);
    }
    
    return ret;
}


void simo_memory_store_deinit(void)
{
    simo_AT45DB041E_delete(_memory_app);

}


uint16_t simo_memory_store_add_page(char* data, uint8_t len)
{
    char buffer_static[256];
    uint16_t _counter = _get_counter();  // obtengo el contador de la memory


    if(_counter >= MAX_DATA) return _counter; // MAXIMA CANTIDAD DE DATOS, NO SE ALMACENA NADA MAS
    uint32_t _page = _counter +DATA_OFFSET;

    //darle formato valido al string y dejarlos en buffer_string

    add_simo_format(data,buffer_static);


    if(buffer_static[0] == CHAR_INIT_SIMO)
    {

        simo_AT45DB041E_save_data(_memory_app,(uint8_t*)buffer_static,strlen(buffer_static)+1,_page,0);
        sleep_us(100);
        _counter+=1;
        _set_counter(_counter);

    }


  
    return _counter;
}



bool simo_memory_store_read_page(uint8_t* buffer,uint8_t len,uint16_t index)
{


    uint16_t counter = _get_counter();
    bool ret = false;

    // leo los primeros 2 bytes de la pagina seleccionada

    uint16_t _page = index + DATA_OFFSET;
    simo_AT45DB041E_read_data(_memory_app,buffer,2,_page,0);
    sleep_us(100);

    if( buffer[0] == CHAR_INIT_SIMO)
    {
        uint8_t len_msg = (uint8_t)buffer[1];
        simo_AT45DB041E_read_data(_memory_app,buffer,len_msg+2,_page,0); // avanzo dos posiciones

        ret = true;
    }

    return ret;   // en el array no debe existir el formato simo (los dos primero bytes)

 


  
}

void simo_memory_store_full_clear()
{
    simo_AT45DB041E_full_erase(_memory_app);
   
}


uint16_t simo_memory_read_all(print_funcion print)
{
    uint16_t counter = _get_counter();
    uint16_t count_msg = 0;
    char buffer_print[250];
    char buffer[200];
    sprintf(buffer_print,"\n\n\nLa cantidad almacenados en memoria es: %d\r\n",counter);
    print(buffer_print);
    bool msg_valid= false;
    
    for(uint16_t index=0 ; index< counter; index+=1)
    {
       msg_valid =  simo_memory_store_read_page(buffer,200,index);
       if(true)
       {
            sprintf(buffer_print,"--mem:%d)=> %s\r\n",index,buffer);
            print(buffer_print);
            count_msg +=1;

       }
     

      
        
    }
    return count_msg;    // devuelvo la cantidad de mensajes validos
}



void simo_memory_clear_counter()
{
    _set_counter(0);
}
