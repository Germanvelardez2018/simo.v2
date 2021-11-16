/**
 * @file main.c
 * @author German Velardez (germanvelardez@gmail.com)
 * @brief 
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
#include "simo/storage/memory/AT45DB041E.h"
#include <string.h>
#include <stdio.h>



#define MENSAJE_SERIAL  "hola mundo \r\n"
#define COUNTER_MSG     "contador = %d\r\n"


static void debug_print(char* msg)
{
    simo_uart_write_buffer(SIMO_UART0,msg,strlen(msg));

}








void serial_task(void* params)
{
    #define SPI         SIMO_SPI1
    #define SPI_FREQ     100*1000 // 1mhz
    #define CHIP_SELECT  9

    char buffer[200];
    simo_uart_init(SIMO_UART0,115200);  
    //creo una memoria
    vTaskDelay(5000); 
    bool ret = simo_memory_store_init();

    if (ret )
    {
       
     
      uint16_t counter = 0;


        sprintf(buffer,"Memoria iniciada \r\n");
        simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));

     //   simo_memory_store_full_clear();       
        vTaskDelay(5000);
     //   _set_counter(0);
    }
    else
    {   sprintf(buffer,"Erro al iniciar memoriar \r\n");
        simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));
    }
    #define MSG_SIZE    100
    char mensaje_guardado[MSG_SIZE];
    char mensaje_escrito[MSG_SIZE] = "APP MEMORY STORE contador:%d \r\n";
    uint16_t counter= 0;
    
    while(1)
    {
     
        counter = _get_counter();
        sprintf(mensaje_escrito,"APP MEMORY STORE )c= A");
        uint16_t pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"APP MEMORY STORE )c= B");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"APP MEMORY STORE )c= C");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"APP MEMORY STORE )c= D");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        sprintf(mensaje_escrito,"APP MEMORY STORE )c= E");
         pos = simo_memory_store_add_page(mensaje_escrito,strlen(mensaje_escrito)+1);
        char b[100];
        sprintf(b,"posicion escritas:%d\r\n",pos);
        simo_uart_write_buffer(SIMO_UART0,b,strlen(b)+1);


        vTaskDelay(4000);
   
     
     
        
         

   
        simo_memory_read_all(debug_print);

        while(1)
        {
            vTaskDelay(1000);
        }
        

       
    }
}

int main(void)
{
   
   
    BaseType_t ret =   xTaskCreate(serial_task,"serial test",10000,0,3,0);
  
    vTaskStartScheduler();
    while(1)
    {

    }

    
}



