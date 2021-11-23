/**
 * @file core.h
 * @author German Velardez  (gvelardez@inti.gob.ar)
 * @brief  Core de la aplicacion. En este archivo van elementos indispensables para la aplicacion.
 *         Se incluye en todos los modulos
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#ifndef   _SIMO_CORE_H
#define   _SIMO_CORE_H


#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"



typedef void (*print_out)(char*);
//! Funcion de objeto debug
typedef void (*dbg_print)(char*,uint32_t);


//! Funcion delay rtos para inyectar a  modulos con tiempos de respuesta altos

typedef void (*delay_rtos)(const TickType_t xTicksToDelay);


#endif