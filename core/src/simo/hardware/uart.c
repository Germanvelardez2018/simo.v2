/**
 * @file uart.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion de capa para manejor del hardware UART (NIVEL 0)
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */


//!Libreria simo
#include "simo/drivers/uart.h"
#include "simo/drivers/gpio.h"
//!librerias del fabricante
#include "hardware/uart.h"
#include "hardware/irq.h"


//definiciones asociadas al hardware espeficico asociado


#define N_UART 2 //! Numero de uart disponibles   
#define UART_DEFAULT uart0



//!Pines asociados
/*!  UART0 GPIOS: TX: 1, RX: 2      opcionalmente    TX: 12, RX:13*/

#define UART0                   uart0
#define UART0_TX                0
#define UART0_TX_OPTIONAL       12
#define UART0_RX                1
#define UART0_RX_OPTIONAL       13



/*!  *    UART0 GPIOS: TX: 4, RX: 5      opcionalmente    TX: 8, RX: 9 */
#define UART1 uart1
#define UART1_TX                4
#define UART1_TX_OPTIONAL       8
#define UART1_RX                5
#define UART1_RX_OPTIONAL       9



//! Baudrare validos para la aplicacion

#define N_BAUDRATES  5
 static  uint32_t  _baudrates[N_BAUDRATES]=
 {
        9600,
        19200,
        38400 ,
        57600,
        115200
 };
   




/**
 * @brief Configuro los pines correspondiente con el puerto seleccionado
 * 
 * @param uart 
 * @return ** void 
 */


static void  _set_pins(uart_t uart)
{

    uint8_t pin_rx;
    uint8_t pin_tx;
     switch (uart)
    {
    case SIMO_UART0:
        pin_tx = UART0_TX;
        pin_rx = UART0_RX;
        
        break;
    case SIMO_UART1:
        pin_tx = UART1_TX;
        pin_rx = UART1_RX;
        break;   
    default:
        pin_tx = UART0_TX;
        pin_rx = UART0_RX;
        break;
    }
       simo_gpio_set_uart(pin_rx);
       simo_gpio_set_uart(pin_tx);
//    gpio_set_function(pin_rx,GPIO_FUNC_UART);
//    gpio_set_function(pin_tx,GPIO_FUNC_UART);  
}


/**
 * @brief  Retorna un valor de baudrate valido de la tabla previamente definida
 * 
 * @param baudrate 
 * @return ** uint32_t 
 */


static uint32_t _get_baudrate(uint32_t baudrate)
{
    int8_t c= 0;
    while( (baudrate > _baudrates[c]) && (c < N_BAUDRATES))
    {
        c++;
    }
    return _baudrates[c];
}





/**
 * @brief Retorna una instancia de harware uart 
 * 
 * @param uart 
 * @return ** uart_inst_t* 
 */


static uart_inst_t*  _get_uart(uart_t uart)
{
   
    switch (uart)
    {
    case SIMO_UART0:
        return  uart0;
        break;
    case SIMO_UART1:
        return  uart1;    
    default:
        return  UART_DEFAULT;
        break;
    }
}



void simo_uart_init(uart_t uart, uint32_t baudrate)
{
    uart_inst_t* u = _get_uart(uart);
    uint32_t b = _get_baudrate(baudrate);
    uart_init(u,b);
    _set_pins(uart);

}



void simo_uart_deinit(uart_t uart)
{
    uart_inst_t* u = _get_uart(uart);
    uart_deinit(u);

}



bool simo_uart_is_enabled(uart_t uart)
{
   uart_inst_t* u = _get_uart(uart);
   
   bool res = uart_is_enabled(u);
   return res;
}




bool simo_uart_read_available(uart_t uart, uint32_t timeout_us)
{
    uart_inst_t* u = _get_uart(uart);
    bool   res = uart_is_readable_within_us(u,timeout_us);
    return res;
}




 void simo_uart_write_buffer(uart_t uart, uint8_t* buffer, uint32_t len_buffer)
 {
    uart_inst_t* u = _get_uart(uart) ;
    uart_write_blocking(u,buffer,len_buffer);
 }



uint32_t simo_uart_read_buffer(uart_t uart ,uint8_t* buffer,uint32_t len_buffer,uint_fast32_t timeout_us )
{
    uart_inst_t* u = _get_uart(uart) ;   
    uint32_t counter= 0;
    while(uart_is_readable_within_us(u,timeout_us) && counter <= len_buffer)
    {
        buffer[counter] = uart_getc(u);
        counter ++;
    }
    return counter;

}



void simo_set_rx_interrupccion(uart_t uart,uart_irq_callback_t function_handler)
{

    uart_inst_t* u = _get_uart(uart);
    //deshabilitamos el FIFO's
    uart_set_fifo_enabled(u,false);


    int UART_IRQ = u == uart0 ? UART0_IRQ : UART1_IRQ;
    
    irq_set_exclusive_handler(UART_IRQ,function_handler); 

    irq_set_enabled(UART_IRQ, true);
    

    //Configuro la FIFO para rx
    uart_set_irq_enables(u,true,false);        

    //habilitamos nuevamente el fifo
    uart_set_fifo_enabled(u,true);

}



char simo_uart_get_char(uart_t uart)
{
   uart_inst_t* u = _get_uart(uart);
   char c = uart_getc(u);
   return c;
}
    


