/**
 * @file interface.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion del interfacez para abstraer hardware. 
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "simo/core.h"
#include "simo/comm/interface.h"




interface_t* simo_interface_create(init_function init, write_function write, read_function read)
{
    // verificar parametros
    if ( (init == NULL) | (write == NULL) | (read == NULL) ) return NULL;

    interface_t* interface = (interface_t*) malloc(sizeof(interface_t));

    if( interface == NULL) return NULL;

    //asigno funciones
    interface->init = init;
    interface->read = read;
    interface->write = write;


    return interface;
}


void simo_interface_delete(interface_t* interface)
{
    free(interface);
}


void simo_interfaces_init(interface_t* interface)
{
    interface->init();
}


void simo_interface_write(interface_t* interface,char* msg,uint32_t len)
{
    interface->write(msg,len);
}


uint32_t simo_interface_read(interface_t* interface,char* buffer, uint32_t len_buffer)
{
    uint32_t res = interface->read(buffer,len_buffer);
    return res;
}
