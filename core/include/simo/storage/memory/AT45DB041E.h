/**
 * @file AT45DB041E.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Driver para manejar la memoria flash AT45DB041E. No usar de manera directa en aplicacion
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef _AT45DB041E_H
#define _AT45DB041E_H




#include "simo/hardware/spi.h"   //! Necesario libreria SIMO


/**
 * @brief Objeto memoria AT45DB041E
 * 
 */
typedef struct 
{   //! Interfaz de hardware asociada
    spi_t spi;
    //!Pin de habilitacion (Chip select)          
    uint32_t cs_pin;
    //! El hardware SPI esta inicializado?    
    bool    spi_ready;
    //! Frecuencia de transmicion SPI    
    uint32_t freq;

}AT45DB041E_t;






/**
 * @brief Retorna un puntero instancia de AT45DB041E_t
 * 
 * @param spi      puerto SPI a utilizar
 * @param cs_pin   pin de chip select
 * @param freq     Frecuencia de trabajo
 * @return ** AT45DB041E_t* 
 */
AT45DB041E_t* simo_AT45DB041E_create(spi_t spi, uint32_t cs_pin,uint32_t freq);


/**
 * @brief Liberar memoria de instancia AT45DB041E
 * 
 * @param mem  puntero de instancia AT45DB041E
 * @return ** void 
 */
void simo_AT45DB041E_delete(AT45DB041E_t* mem);


/**
 * @brief Inicio el objeto memoria
 * 
 * @param mem 
 * @return true 
 * @return false 
 */
bool simo_AT45DB041E_init(AT45DB041E_t* mem);






/**
 * @brief Borrar memoria completa. Tambien es posible borrar por sectores
 * 
 * @param mem  objeto memoria a borrar
 * @return ** void 
 */
void simo_AT45DB041E_full_erase(AT45DB041E_t* mem);




/**
 * @brief  Guardar datos en memoria. Ingresar numero de pagina y posicion dentro de la pagina
 * 
 * @param mem           puntero a objeto de memoria
 * @param buffer        buffer de datos a enviar
 * @param buffer_len    tamanio de buffer de datos
 * @param page          numero de pagina 
 * @param position_page posicion dentro de la pagina
 * @return ** void 
 */
void simo_AT45DB041E_save_data(AT45DB041E_t* mem,
                                 uint8_t* buffer,
                                 uint32_t buffer_len,
                                 uint32_t page,
                                 uint32_t position_page);

/**
 * @brief  Leer datos en memoria. Ingresar numero de pagina y posicion dentro de la pagina
 * 
 * @param mem               puntero a objeto memoria
 * @param buffer            buffer donde almacenar los datos leidos
 * @param buffer_len        tamanio del buffer de datos
 * @param page              numero de pagina
 * @param position_page     posicion dentro de la pagina
 * @return ** void 
 */
void simo_AT45DB041E_read_data(AT45DB041E_t* mem,
                                uint8_t* buffer,
                                uint32_t buffer_len,
                                uint32_t page,
                                uint32_t position_page);



#endif