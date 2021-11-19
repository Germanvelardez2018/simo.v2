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
        if( interface == NULL) return NULL;
        SIM_device_t* sim = (SIM_device_t*) malloc(sizeof(SIM_device_t));
        if (sim == NULL) return NULL;
        sim->hardware = interface;
        
        return sim;

    }


    void simo_sim_device_delete(SIM_device_t* sim)
    {
        if (sim!=NULL)
        {
            free(sim->hardware);
            free(sim);   
        }
    }




  
    void simo_sim_device_write(SIM_device_t* sim,char* msg,uint32_t len)
    {
        simo_interface_write(sim->hardware,msg,len);
    }

  
    uint32_t simo_sim_device_read(SIM_device_t* sim )
    {
        uint32_t ret = simo_interface_read(sim->hardware,sim->buff_in,SIM_BUFFER_SIZE);
        return ret;
    }