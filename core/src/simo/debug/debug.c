/**
 * @file debug.c
 * @author German Velardez(gvelardez@inti.gob.ar)
 * @brief  Funciones para configurar puerto de debug 
 * @version 0.1
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "simo/debug/debug.h"


#define DEBUG_HARDWARE_DEFAULT                  SIMO_UART0
#define DEBUG_BAUDRATE_DEFAULT                  115200


#define DEBUG_FORMAT            "[%s] %s \r\n"   // [name_module] msg


static debug_t* _debug = NULL;



/**
 * @brief Esta funcion inicializa el puerto SIMO_UART0 que es el hardware por default del debug
 * 
 * @return ** void 
 */
static   void __default_hardware_init()
{
    simo_uart_init(DEBUG_HARDWARE_DEFAULT,DEBUG_BAUDRATE_DEFAULT);

}


/**
 * @brief  Enviamos datos por puerto debug por default (SIMO_UART0)
 * 
 * @param buffer 
 * @param len 
 * @return ** void 
 */
static  void __default_print(char* buffer, uint32_t len)
{
    simo_uart_write_buffer(DEBUG_HARDWARE_DEFAULT,(uint8_t*)buffer,len);
}




/**
 * @brief  inicio y configuro el puerto de debug
 * 
 
 * @param buffer_len 
 * @return true 
 * @return false 
 */
 bool simo_debug_init( uint32_t buffer_len)
 {


    bool ret= false;

    if (_debug == NULL)
    {
        _debug = (debug_t* )malloc(sizeof(debug_t));

        if (_debug != NULL)
        {
            _debug->buffer = (char*) malloc(sizeof(char)*buffer_len);
            if (_debug->buffer != NULL)
            {
               
      
                    _debug->len = buffer_len;
                    _debug->hardware_init = __default_hardware_init;
                    _debug->print = __default_print;
                    _debug->hardware_init(); // iniciamos hardware
                    ret= true;
                
            }
            else
            {
                free(_debug); //
            }
        }

        return ret;

        
    }
}
 




void simo_debug_print(char* msg,char* name_module)
{
    

    if(_debug != NULL)
    {
          sprintf(_debug->buffer,DEBUG_FORMAT,name_module,msg);
          
          _debug->print(_debug->buffer,strlen(_debug->buffer));

    }
  

}



void simo_debug_set_hardware(dbg_hardware_init hardware_init, dbg_print print)
{
    if(_debug !=NULL & hardware_init != NULL & print != NULL) // el debug debe ser inicializado antes
    {
        _debug->hardware_init = hardware_init;
        _debug->print = print;
    }
}
