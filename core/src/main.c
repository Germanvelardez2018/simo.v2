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

#include "simo/drivers/uart.h"
#include "simo/storage/memory_store.h"
#include "simo/debug/debug.h"  //! probemos el simo debug
#include "simo/comm/comm.h"
#include "simo/utiles/cjson.h"       // para el manejor del formato json
#include "simo/timer/timer.h"      // llamado de funciones de manera periodica
#include <string.h>
#include <stdio.h>


#include "simo/timer/wdt.h"


#define MENSAJE_SERIAL  "hola mundo \r\n"
#define COUNTER_MSG     "contador = %d\r\n"

#define PIN_LED 25

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
    simo_debug_print("iniciamos flash task","serial task");
    char buffer[200];
    
    //creo una memoria
    vTaskDelay(2000); 
    bool ret = simo_memory_store_init();

    if (ret )
    {
        
        simo_debug_print("__Memoria iniciada__","serial task");
        //Para borra memoria,compilar e  implementar y luego comentar y volver a compilar
        //simo_memory_store_full_clear(vTaskDelay);    
        //vTaskDelay(5000);
         //simo_memory_store_clear_counter();
          
       
    }
    else
    {   sprintf(buffer,"Error al iniciar memoriar \r\n");
        //simo_uart_write_buffer(SIMO_UART0,buffer,strlen(buffer));
    }
    #define MSG_SIZE    100
    char mensaje_guardado[MSG_SIZE];
   
    uint16_t counter= 0;
    







    // creo un json
    
    #define BUFFER_JSON   254  // Maximo valor que se puede almacenar por pagina
    cjson_t* json = simo_cjson_create(BUFFER_JSON);

    if (json != NULL)
    {
        //cargo el json con elementos
      uint8_t r = 1 ;

      if(r ==1) r = simo_cjson_add_int(json,"posicionX",-2300000);   // add element with type INT
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"posicionY",-2221117);
      vTaskDelay(100);
      if(r == 1)r = simo_cjson_add_string(json,"config","comando de configuracion");
      if(r ==1) r = simo_cjson_add_int(json,"Bateria",-97);
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor1",23000);   // add element with type INT
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor2",2217);
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor3",17);
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor4",23000);   // add element with type INT
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor5",2217);
      vTaskDelay(100);
      if(r ==1) r = simo_cjson_add_int(json,"sensor6",17);
     vTaskDelay(100);

   
       char* b_json;
       b_json = simo_cjson_get_string(json);
       if( b_json != NULL)
       {
         uint16_t pos = simo_memory_store_add_page(b_json,strlen(b_json)+1);
         uint16_t datos_validos= simo_memory_read_all(debug_print,vTaskDelay);
         simo_cjson_delete(json);
       }
        
    }
    while(1)
    {
       
            vTaskDelay(1500);      
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
        .timeout_us = 1000   // 10 ms tiempo maximo.
    };
    vTaskDelay(5000);
    vTaskDelay(2000);
    simo_debug_print("tarea com","comm task");
    simo_debug_print("iniciamos test sim device","comm_task");
    vTaskDelay(4000);
    bool ret = simo_comm_init(debug_device,vTaskDelay); // inyecto delay de rtos al modulo
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






static void get_print(void)
{
            simo_debug_print("estamos en timer_print","get print");
            vTaskDelay(10);

}


int main(void)
{
  
    simo_wdt_init();  // Iniciamos el wdt
    bool debug =  simo_debug_init(300);
    BaseType_t ret;
    ret =   xTaskCreate(flash_task,"flash test",6000,0,(configMAX_PRIORITIES - 2),0);
  //  ret =   xTaskCreate(comm_task,"sim device test",10000,0,3,0);

    //creo un timer   de prueba, solo imprime cada 6 segundos
    soft_timer_t timer_print  ;
    uint8_t success;
    //inicio el timer
    success  =  simo_timer_create(&timer_print,get_print,6000,1);
   
    vTaskStartScheduler();
    while(1)
    {

    }

    
}



