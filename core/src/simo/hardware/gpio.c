/**
 * @file gpio.c
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion de capa para manejor del hardware gpio (NIVEL 0)
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "hardware/gpio.h"  // ! Libreria del fabricante
#include "simo/drivers/gpio.h" 




    void simo_gpio_set_i2c(uint8_t gpio_pin)
    {
         gpio_set_function(gpio_pin,GPIO_FUNC_I2C);
    }



    void simo_gpio_set_spi(uint8_t gpio_pin )
    {
        gpio_set_function(gpio_pin,GPIO_FUNC_SPI);

    }
    

    void simo_gpio_set_uart(uint8_t gpio_pin )
    {
        gpio_set_function(gpio_pin,GPIO_FUNC_UART);
    }



    void simo_gpio_init(uint8_t gpio_pin)
    {
      gpio_init(gpio_pin);   
    }


  
    void simo_gpio_set_dir(uint8_t gpio_pin,bool output)
    {
        gpio_set_dir(gpio_pin,output);
    }


    void simo_gpio_put(uint8_t gpio_pin,bool value)
    {
        gpio_put(gpio_pin,value);
    }




    void simo_gpio_set_pullup(uint8_t gpio_pin,bool value)
    {
        // verifico valor de pull down
        bool down =  gpio_is_pulled_down(gpio_pin);
        //mantengo valor de pull down y agrego valor de pull up
        gpio_set_pulls(gpio_pin, value, down);
    }

    void simo_gpio_set_pulldown(uint8_t gpio_pin, bool value)
        {
            //verifico valor de pull up
            bool up = gpio_is_pulled_up(gpio_pin);
            //mantengo valor de pull up y agrego valor de pull down
            gpio_set_pulls(gpio_pin, up, value);
        }


   void simo_gpio_set_callback_irq(uint8_t gpio_pin, uint32_t event, gpio_irq_callback_t funct_callback,bool enable)
   {
        gpio_set_irq_enabled_with_callback(gpio_pin,0,enable,   funct_callback);
   }