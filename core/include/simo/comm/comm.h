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

    #include "simo/core.h"
    #include "simo/utiles/cmd_request.h"


 /**
  * @brief Iniciamos modulo de comunicacion
  * 
  * @param print_debug  Funcion de salida debug
  * @param delay_rtos   Delay asistido por rtos
  * @return true 
  * @return false 
  */
    bool simo_comm_init(print_out print_debug,delay_rtos delay_rtos);

    /**
     * @brief  Liberamos recursos asociados con la comunicaicon
     * 
     * @return ** void 
     */
    void simo_comm_delete(void);

   


    /**
     * @brief Enviamos datos mediante el objeto modulo de comunicacion
     * 
     * @param msg 
     * @return ** bool , mensaje enviado correctamente
     */
    bool simo_comm_send_message(char* msg);


    /**
     * @brief  Envia una peticion desde el modulo comm
     * @note las peticiones cmd_request tiene 3 elemento, el commando, la respuesta esperada y el timeout en us
     * @param req 
     * @return true  si respuesta esperada coinciden con respuesta coinciden
     * @return false 
     */
    bool simo_comm_send_request(cmd_request_t* req);
#endif