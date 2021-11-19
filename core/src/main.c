/**
 * @file main.c
 * @author German Velardez (germanvelardez@gmail.com)
 * @brief  Aplicacion SIMO v2
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"

#include "simo/hardware/uart.h"
#include "simo/storage/memory_store.h"
#include "simo/debug/debug.h"  //! probemos el simo debug
#include "simo/comm/comm.h"
#include <string.h>
#include <stdio.h>




#define MENSAJE_SERIAL  "hola mundo \r\n"
#define COUNTER_MSG     "contador = %d\r\n"



static void debug_print(char* msg)
{
  
    simo_debug_print(msg,"flash memory");


}






/**
 * @brief Tarea para probas memoria flash
 * 
 * @param params 
 * @return ** void 
 */

void flash_task(void* params)
{

    vTaskDelay(5000);
    simo_debug_print("comenzamos el programa","serial task");
    char buffer[200];
    //simo_uart_init(SIMO_UART0,115200);  
    //creo una memoria
    vTaskDelay(2000); 
    bool ret = simo_memory_store_init();

    if (ret )
    {
       
     
      uint16_t counter = 0;


        sprintf(buffer,"Memoria iniciada \r\n");
        //simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));

          // simo_memory_store_full_clear();       
           vTaskDelay(5000);
          // simo_memory_clear_counter();
       
    }
    else
    {   sprintf(buffer,"Erro al iniciar memoriar \r\n");
        //simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));
    }
    #define MSG_SIZE    100
    char mensaje_guardado[MSG_SIZE];
    char mensaje_escrito[MSG_SIZE] ;
    uint16_t counter= 0;
    
    while(1)
    {
     
     
        
        sprintf(mensaje_escrito,"{Este es un json }");
        uint16_t pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"{datos de configuracion}");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"{Mqtt servidor: kkkx.mqtt}");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"1234mrk");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"mensaje de alerta");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        char b[100];
        sprintf(b,"posicion escritas:%d\r\n",pos);
        //simo_uart_write_buffer(SIMO_UART0,b,strlen(b)+1);

    
   
 
        
        
         

   
        uint16_t datos_validos= simo_memory_read_all(debug_print);
        sprintf(b,"cantidad de datos validos:%d\r\n",datos_validos);
        //simo_uart_write_buffer(SIMO_UART0,b,strlen(b)+1);

        while(1)
        {
            vTaskDelay(1000);
        }
        

       
    }
}



static void debug_device(char* msg)
{
  
    simo_debug_print(msg,"comm debug");


}

/**
 * @brief Tarea para probar comm ( modulo de  comunicacion)
 * 
 * @param params 
 * @return ** void 
 */
static void comm_task(void* params)
{

    cmd_request_t req =
    {
        .p_cmd = "AT\r\n",
        .p_expected_resp="OK\r\n",
        .timeout_us = 10000
    };
    vTaskDelay(5000);
    vTaskDelay(2000);
    simo_debug_print("tarea com","comm task");
    simo_debug_print("iniciamos test sim device","comm_task");
    vTaskDelay(4000);
    bool ret = simo_comm_init(debug_device);

    if(ret)
    {
        simo_debug_print("se creo el device","comm task");
    }
    else
    {
        simo_debug_print("error al crear dispositivo","comm task");
    }
    
    while(1)
    {

      
       if(ret)simo_comm_send_request(&req);
        vTaskDelay(4000);
    }
}

int main(void)
{
   
    bool debug =  simo_debug_init(300);
    BaseType_t ret;
    // ret =   xTaskCreate(flash_task,"flash test",10000,0,3,0);
    ret =   xTaskCreate(comm_task,"sim device test",10000,0,3,0);

  
    vTaskStartScheduler();
    while(1)
    {

    }

    
}



