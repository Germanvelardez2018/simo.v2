/**
 * @file gpio.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Capa de hardware para manejor de puerto GPIO del micro
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */





#ifndef   SIMO_GPIO_H
    
    #define SIMO_GPIO_H
    #include <stdint.h>
    #include <stdbool.h>

    #include "hardware/gpio.h"



    /**
     * @brief 
     * 
     * @param gpio_pin gpio_pin seleccionado 
     * @return ** void 
     */
    void simo_gpio_set_spi(uint8_t gpio_pin );
    
    /**
     * @brief 
     * 
     * @param gpio_pin gpio_pin seleccionado 
     * @return ** void 
     */
    void simo_gpio_set_uart(uint8_t gpio_pin );

    /**
     * @brief 
     * 
     * @param gpio_pin gpio_pin seleccionado 
     * @return ** void 
     */

    void simo_gpio_init(uint8_t gpio_pin);


    /**
     * @brief 
     * 
     * @param gpio_pin gpio_pin seleccionado 
     * @param output   valor de salida. true es salida, false es entrada
     * @return ** void 
     */
    void simo_gpio_set_dir(uint8_t gpio_pin,bool output);




    /**
     * @brief 
     * 
     * @param gpio_pin gpio_pin seleccionado 
     * @param value 
     * @return ** void 
     */
    void simo_gpio_put(uint8_t gpio_pin,bool value);


    /**
     * @brief  Configuro una funcion de interrupcion
     * 
     * @param gpio_pin  gpio_pin seleccionado
     * @param event     Es el uint32_t que se le pasa a la function callback cuando surge la irq.
     * @param funct_callback funcion que maneja la interrupcion 
     * @param enable    Se habilitan las interrupcion. Si es falso la funcion configura pero no habilita la interrupion
     * @note funct_callback :
        *  void (*gpio_irq_callback_t)(uint gpio, uint32_t events);
     * @note El valor event que se envia a la function depende del evento asociado:
 *
            * bit | interrupt
            * ----|----------
            *   0 | Low level
            *   1 | High level
            *   2 | Edge low
            *   3 | Edge high
     * @return ** void 
     */
   void simo_gpio_set_callback_irq(uint8_t gpio_pin, uint32_t event, gpio_irq_callback_t funct_callback,bool enable);


#endif



