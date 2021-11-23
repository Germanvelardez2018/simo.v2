/**
 * @file cmd_request.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef  _SIMO_UTILS_CMD_REQUEST
#define  _SIMO_UTILS_CMD_REQUEST


    #include "simo/core.h"
    typedef struct
    {
        //! comando
        char* p_cmd;
        //! respuesta esperada
        char* p_expected_resp;
        //! tiempo maximo de respuesta
        uint32_t timeout_us;
    }
    cmd_request_t;


#endif
