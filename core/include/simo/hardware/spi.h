/**
 * @file spi.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>







#ifndef   SIMO_SPI_H
    
    #define SIMO_SPI_H
    #include <stdint.h>
    #include <stdbool.h>


    typedef enum {
        //!Interfaz asociada a SPI0 en rp2040
        SIMO_SPI0,     
        //! Interfaz asociada a SPI1 en rp2040
        SIMO_SPI1      
    }spi_t;




    /**
     * @brief  Habilito el hardware spi seleccioando
     * 
     * @param spi  puerto spi seleccionado
     * @param baudrate  baudrate seleccionado
     * @return ** void 
     */

    void simo_spi_init(spi_t spi,uint32_t baudrate);




    /**
     * @brief  Deshabilito el hardware spi seleccionado
     * 
     * @param spi  puerto SPI seleccionado
     * @return ** void 
     */

    void simo_spi_deinit(spi_t  spi);





    /**
     * @brief  Envio un array de bytes por puerto SPI
     * 
     * @param spi  puerto SPI seleccionado
     * @param buf  array de bytes para enviar
     * @param len_buf tamanio del array de byte a enviar
     * @return ** void 
     */

    void simo_spi_write(spi_t  spi, int8_t* buf, uint32_t len_buf );



    /**
     * @brief Consulta la disponibilidad del hardware SPI para leer datos
     * 
     * @param spi  puerto SPI seleccionado
     * @return true 
     * @return false 
     */

    bool simo_spi_isimo_readable(spi_t  spi);




    /**
     * @brief Leer una secuencia de bytes desde el puerto SPI
     * 
     * @param spi      puerto SPI seleccionado
     * @param buf      buffer donde se almacenaran los datos
     * @param tx_data  data testigo a enviar. No importa
     * @param len_buf  tamanio del buffer de almacenamiento de datos
     * @return ** void 
     */
    void simo_spi_read(spi_t  spi,int8_t* buf,uint8_t tx_data,uint32_t len_buf);



    /**
     * @brief Enviar una secuencia de bytes desde el puerto SPI
     * 
     * @param spi      puerto SPI seleccioando
     * @param buf_w    buffer con los datos a enviar
     * @param buff_r   buffer de recepcion
     * @param len_buff  tamanio de ambos baffers
     * @return ** void 
     */

    void simo_spi_write_read(spi_t spi, uint8_t* buf_w, uint8_t* buff_r, uint32_t len_buff);


#endif