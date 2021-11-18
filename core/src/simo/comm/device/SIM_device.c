/**
 * @file SIM_device.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief  Implementacion de objeto SIM devices y funciones asociadas
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include "simo/comm/device/SIM_device.h"
#include <stdlib.h>



    SIM_device_t* simo_sim_device_create(interface_t* interface)
    {
        return NULL;
    }


    void simo_sim_device_delete(SIM_device_t* sim)
    {

    }




  
    void simo_sim_device_write(SIM_device_t sim,char* msg,uint32_t len)
    {

    }

  
    uint32_t simo_sim_device_read(SIM_device_t sim )
    {
        return 0;
    }