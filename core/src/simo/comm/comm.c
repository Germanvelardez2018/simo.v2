/**
 * @file comm.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  API para la comunicacion del sistema
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "simo/core.h"
#include "simo/comm/comm.h"
#include "simo/comm/device/SIM_device.h"
#include "simo/core.h"
#include "simo/hardware/uart.h"
#include "simo/comm/comm.h"
#include "pico/time.h"
    //!Objeto para manejar la comunicacion del sistema
    static SIM_device_t* __SIM;
    static interface_t* __interface;

    static print_out __print;


    #define COMM_UART           SIMO_UART1
    #define COMM_BAUDRATE       115200
    #define COMM_TIMEOUT_US     100                 
    //! FUNCIONES PARA COMUNICAR EL SISTEMA



    static void __init_interface(void)
    {
        simo_uart_init(COMM_UART,COMM_BAUDRATE);

    }

    static void __write_interface(char* buffer,uint32_t len)
    {
        simo_uart_write_buffer(COMM_UART,(uint8_t*)buffer,len);
    }


    static uint32_t __read_interface(char* buffer,uint32_t len)
    {
        uint32_t ret = simo_uart_read_buffer(COMM_UART,(uint8_t*)buffer,len,COMM_TIMEOUT_US);
        return ret;
    }

    static bool __create_interface(void)
    {   bool ret= false;

        __interface = simo_interface_create(__init_interface,__write_interface,__read_interface);


        if(__interface != NULL) 
        {
            simo_interfaces_init(__interface);  // iniciamos la interfaz
            ret = true;
        }
        return ret;
    }





    bool simo_comm_init(print_out print_debug)
    {
        bool ret = false;
        if(__SIM== NULL)
        {

            bool ret_interface = __create_interface(); // creamos interfaces con funciones static definidas anteriormente
            if(ret_interface )
            {
                __SIM = simo_sim_device_create(__interface);
                if(__SIM == NULL)
                {
                    free(__interface); // libero interface
                }
                else
                {
                    ret = true; // inicio todo correctamente
                    if(print_debug != NULL)
                    {
                        __print = print_debug;
                    }
                }
               
            }
            
        }
        return ret;
    
    }

  
    void simo_comm_delete(void)
    {
        simo_sim_device_delete(__SIM);
    }

  

 
    bool simo_comm_send_message(char* msg)
    {
        simo_sim_device_write(__SIM,msg,strlen(msg));
        __print(msg);

        return false;
    }


    bool simo_comm_send_request(cmd_request_t* req)
    {

        simo_sim_device_write(__SIM,req->p_cmd,strlen(req->p_cmd));
        __print(req->p_cmd);
      
      
        uint32_t num = simo_sim_device_read(__SIM);

        if(num)
        {
            char out[200];
            __SIM->buff_in[num]=0;
            sprintf(out,"se recibio:%s",__SIM->buff_in);
            __print(out);
        }

        bool ret = (num==0)?false:true;
        return ret;
    }