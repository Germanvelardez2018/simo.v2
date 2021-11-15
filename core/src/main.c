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

#include "simo/harware/uart.h"
#include <string.h>

#define MENSAJE_SERIAL  "hola mundo \r\n"

void serial_task(void* params)
{

    char buffer[]= MENSAJE_SERIAL;
    simo_uart_init(SIMO_UART0,115200);
    while(1)
    {
        simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));
        vTaskDelay(1000);
    }
}

int main(void)
{
   
   
    BaseType_t ret =   xTaskCreate(serial_task,"serial test",5000,0,3,0);
  
    vTaskStartScheduler();
    while(1)
    {

    }

    
}



