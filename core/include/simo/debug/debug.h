/**
 * @file debug.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Objeto debug y funciones asociadas
 * @version 0.1
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "simo/hardware/uart.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//! Funcion de objeto debug
typedef void (*dbg_print)(char*,uint32_t);
typedef void(*dbg_hardware_init)();






//! Objeto  debug.
typedef struct {

 //!Buffer para formatear mensaje antes de enviar
 char*       buffer;
 //!Funcion para imprimir por puerto. Tiene un valor por default UART0 
 dbg_print   print;
 //! Funcion para iniciar el hardware asociado
 dbg_hardware_init hardware_init; 
 //! Tamanio del buffer completo. Es decir mensaje mas formato deben poder almacenarse
 uint32_t len;   
} debug_t;








/**
 * @brief Inicia y configura el puerto de debug
 * 
 * @param buffer_len 
 * @return true 
 * @return false 
 */
 bool simo_debug_init( uint32_t buffer_len);



/**
 * @brief 
 *         Imprime mensaje mas formato 
 * @param msg  mensaje @note tamanio maximo buffer - name module -10. aproximado. Depende de DEBUG_FORMAT
 * @param name_module  Nombre del modulo o funcion desde donde es llamado esta funcion
 * @return ** void 
 */
void simo_debug_print(char* msg,char* name_module);

/**
 * @brief Configura una salida diferente a la por defualt ( SIMO_UART0)
 * 
 * @param hardware_init 
 * @param print 
 * @return ** void 
 */
void simo_debug_set_hardware(dbg_hardware_init hardware_init, dbg_print print);
