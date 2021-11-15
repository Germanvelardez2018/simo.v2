/**
 * @file uart.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Capa de abstraccion para manejar el harware uart del micro RP2040 (Raspberry PI PICO)
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef  _SIMO_HARDWARE_UART_
  #define _SIMO_HARDWARE_UART_

  #include "simo/core.h"
  #include "simo/config.h"
  #include <stdbool.h>
  /**
   * @brief Enumeracion de las interfaces uart disponibles en el micro
   * 
   */
  typedef enum {
      //! Interfaz uart0 en rp2040
        SIMO_UART0, 
      //! Interfaz uart1 en rp2040
        SIMO_UART1 
    } uart_t;


    typedef void (*uart_irq_callback_t)(void);    //! Puntero a funcion de interrupcion



  /**
   * @brief  Inicio el harware uart selecionado
   * 
   * @param uart_t      interfaz seleccionada
   * @param baudrate  baudrate seleccionado
   * 
   * @return ** void 
   */
    void simo_uart_init(uart_t uart, uint32_t baudrate);



  /**
   * @brief Desconfigura el harware seleccionado
   * 
   * @param uart  interfaza selecionada
   * @return ** void 
   */
    void simo_uart_deinit(uart_t uart);


  /**
   * @brief Consulta si el puerto uart seleccionado puede enviar datos
   * 
   * @param uart puerto seleccionado
   * @return true 
   * @return false 
   */
  bool simo_uart_is_enabled(uart_t uart);



  /**
   * @brief Consultar si el puerto uart seleccionado puede leer datos
   * 
   * @param uart puerto seleccioando
   * @return true 
   * @return false 
   */
  bool simo_uart_read_available(uart_t uart,uint32_t timeout);


  /**
   * @brief Envio un buffer mediante el uart selecionado
   * 
   * @param buffer    buffer a enviar
   * @param len_buffer  tamanio de buffer a enviar
   * @return ** void 
   */
  void simo_uart_write_buffer(uart_t uart, uint8_t* buffer, uint32_t len_buffer);


  /**
   * @brief 
   * 
   * @param buffer buffer donde se almacenan los elementos leidos por el uart 
   * @param len_buffer  tamanio del buffer.
   * @param timeout     tiempo maximo en us.
   * @return ** uint32_t cantidad de elementos leios
   */
  uint32_t simo_uart_read_buffer(uart_t,uint8_t* buffer,uint32_t len_buffer,uint_fast32_t timeout );


  /**
   * @brief 
   * 
   * @param uart  puerto uart seleccionado
   * @param function_handler  function para el manejo de la interrupcion
   * @return ** void 
   */
  void simo_set_rx_interrupccion(uart_t uart,uart_irq_callback_t function_handler);



  /**
   * @brief 
   * 
   * @param uart  puerot uart seleccionado
   * @return ** char 
   */
  char simo_uart_get_char(uart_t uart);


#endif
