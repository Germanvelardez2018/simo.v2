/**
 * @file memory_store.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief 
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

/*
 *  Memoria utilizada: at45db041E
 * PAGINAS: 2048        DIRECCION DE 11 BITS
 * BLOQUES: 256         DIRECCION DE 8 BITS
 * SECTORES: 8  
*/
#define N_PAGES                 2048
#define SIZE_PAGE               256
#define ADDRES_COUNTER          0
#define ADDRESS_START           10
#define DATA_OFFSET             100


                   




// variable privada de memoria a utilizar

static AT45DB041E_t* _memory_app;
#define SPI_APP             SIMO_SPI1  //! Utilizo el SPI1
#define CS_PIN              9          //! El chip select utilizado sera el pin 9
#define MEMORY_APP_BAUDRATE_FAST       (50*100000) //5 MHz
#define MEMORY_APP_BAUDRATE_LOW        (10*100000) //1 MHz
#define FREQ_APP            MEMORY_APP_BAUDRATE_LOW



 // counter ----|PARTE ALTA[addres = 1]| PARTE BAJA[addres = 0]

 //               buffer[0] == parte baja | buffer[1] = prte alta
 

uint16_t _get_counter()
{
    uint8_t counter[2]={0};

    simo_AT45DB041E_read_data(_memory_app,counter,2,ADDRES_COUNTER,0);

    uint16_t ret = (uint16_t)(counter[0]) | (uint16_t)(counter[1]<< 8) ;  // 
    return ret ;
}




void _set_counter(uint16_t count)
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
    uint16_t _counter = _get_counter();  // obtengo el contador de la memory
    uint32_t _page = _counter +DATA_OFFSET;
    simo_AT45DB041E_save_data(_memory_app,(uint8_t*)data,len,_page,0);
    sleep_us(100);
    _counter+=1;
    _set_counter(_counter);
    return _counter;
}



bool simo_memory_store_read_page(uint8_t* buffer,uint8_t len,uint16_t index)
{

    uint16_t counter = _get_counter();
    bool ret = false;

    // si index es mayor que contador de datos, retorna 0
    if( index <= counter)
    {
        uint16_t _page = index + DATA_OFFSET;
        simo_AT45DB041E_read_data(_memory_app,buffer,len,_page,0);
        ret =true;
    }

 


    return ret;
}

void simo_memory_store_full_clear()
{
    simo_AT45DB041E_full_erase(_memory_app);
}


uint16_t simo_memory_read_all(print_funcion print)
{
    uint16_t counter = _get_counter();

    char buffer_print[250];
    char buffer[200];
    sprintf(buffer_print,"\n\n\nLa cantidad de datos a leer es: %d\r\n",counter);
    print(buffer_print);
    for(uint16_t index=0 ; index< counter; index+=1)
    {
        simo_memory_store_read_page(buffer,200,index);
        sprintf(buffer_print,"--mem:%d)=> %s\r\n",index,buffer);
        print(buffer_print);
    }
    return counter;
}