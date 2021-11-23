/**
 * @file interface.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Interfaz para manejar separar el hardware del los objetos comm
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "simo/core.h"

#ifndef   _SIMO_COMM_INTERFACE_H
#define   _SIMO_COMM_INTERFACE_H



    //! Puntero a funcion para escribir un array de char
    typedef void (*write_function)(char* msg,uint32_t len);


    //*! Puntero a function para leer datos y almacenarlos en array
    //!@note devuelve la cantidad de bytes leidos
    typedef uint32_t (*read_function)(char* buffer,uint32_t len_buffer);



    //!Puntero a funcion para inicializar la interfaz
    typedef void (*init_function)(void);


    typedef struct
    {
        //! Escribir datos a traves de la interfaz
        write_function write;
        //! Leer datos a travez de la interfaz
        read_function read;
        //! Iniciar la interfacez
        init_function init;
    } interface_t;




    /**
     * @brief 
     * 
     * @param init 
     * @param write 
     * @param read 
     * @return ** interface_t* 
     */
    interface_t* simo_interface_create(init_function init, write_function write, read_function read);


    /**
     * @brief 
     * 
     * @param interface 
     * @return ** void 
     */
    void simo_interface_delete(interface_t* interface);


    /**
     * @brief 
     * 
     * @param interface 
     * @return ** void 
     */
    void simo_interfaces_init(interface_t* interface);


  /**
   * @brief 
   * 
   * @param interface 
   * @param msg 
   * @param len 
   * @return ** void 
   */
    void simo_interface_write(interface_t* interface, char* msg, uint32_t len);

  /**
   * @brief 
   * 
   * @param interface 
   * @param buffer 
   * @param len_buffer 
   * @return ** uint32_t 
   */
    uint32_t simo_interface_read(interface_t* interface, char* buffer, uint32_t len_buffer);


#endif