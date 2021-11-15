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
#include "simo/storage/memory/AT45DB041E.h"
#include <string.h>
#include <stdio.h>

#define MENSAJE_SERIAL  "hola mundo \r\n"
#define COUNTER_MSG     "contador = %d\r\n"
void serial_task(void* params)
{
    #define SPI         SIMO_SPI0
    #define SPI_FREQ     100000
    #define CHIP_SELECT  10
    //creo una memoria
    AT45DB041E_t* memory = simo_AT45DB041E_create(SPI,CHIP_SELECT,SPI_FREQ);

    if (memory != NULL)
    {
        // inicio memoria
        simo_AT45DB041E_init(memory);

        
    }

    char buffer[100];
    simo_uart_init(SIMO_UART0,115200);  
    uint16_t counter= 0;
    while(1)
    {
        sprintf(buffer,COUNTER_MSG,counter);
        simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));
        vTaskDelay(1000);
        counter +=1;
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



