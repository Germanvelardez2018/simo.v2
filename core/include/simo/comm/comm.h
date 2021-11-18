/**
 * @file comm.h
 * @author German Velardez  (gvelardez@inti.gob.ar)
 * @brief  Modulo de capa 2 que sirve para gestionar comunicacion mediante hardware externo
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef   _SIMO_COMM_COMM_H
#define   _SIMO_COMM_COMM_H



    /**
     * @brief  Creamos un objeto  modulo de comunicacion (comm)
     * 
     * @return ** void 
     */
    void simo_comm_create(void);

    /**
     * @brief  Liberamos recursos asociados con la comunicaicon
     * 
     * @return ** void 
     */
    void simo_comm_delete(void);

    /**
     * @brief  Iniciamos el modulos de comunicacion
     * 
     * @return ** void 
     */
    void simo_comm_init(void);


    /**
     * @brief Enviamos datos mediante el objeto modulo de comunicacion
     * 
     * @param msg 
     * @return ** void 
     */
    bool simo_send_message(char* msg);

#endif