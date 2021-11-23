/**
 * @file SIM_device.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Driver para el manejo de modulos SIM7000G(NIVEL 1). Depende de SIMO UART
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "simo/comm/interface.h"

#define SIM_BUFFER_SIZE     256
#define SIM_UART            
#define SIM_BAUDRATE


#ifndef   _SIMO_COMM_DEVICES_SIM_H
#define   _SIMO_COMM_DEVICES_SIM_H

    typedef struct{
        //! Buffer de salida para enviar comandos y datos al modulo sim
        char  buff_out[SIM_BUFFER_SIZE];
        //! Buffer de entrada para recibir las respuestas del modulo sim
        char  buff_in[SIM_BUFFER_SIZE];

        //! Interfaz de hardware asociada
        interface_t*  hardware;

    } 
    SIM_device_t;




    /**
     * @brief Creamos un objeto SIM_device
     * 
     * @param interface  interfaz para manejar el hardware asociado. En este caso un puerto uart
     * @return ** SIM_device_t* 
     */
    SIM_device_t* simo_sim_device_create(interface_t* interface);

    /**
     * @brief Liberamos la memoria asociada a un objeto sim Device
     * 
     * @param sim puntero a el objeto a liberar
     * @return ** void 
     */
    void simo_sim_device_delete(SIM_device_t* sim);

    /**
     * @brief 
     * 
     * @param sim  objeto modulo sim
     * @param msg  array de datos a enviar
     * @param len  tamanio de array
     * @return ** void 
     */
    void simo_sim_device_write(SIM_device_t *sim,char* msg,uint32_t len);

    /**
     * @brief 
     * 
     * @param sim 
     * @return ** uint32_t 
     */
    uint32_t simo_sim_device_read(SIM_device_t *sim );




#endif