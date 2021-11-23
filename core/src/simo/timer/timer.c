/**
 * @file timer.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include "simo/timer/timer.h"


/**
  * @brief Funcion que gestiona los handlers de los timers.
  * @retval None
  */


static void generic_handler(TimerHandle_t params)
{
  
    callback_function callback = (callback_function) pvTimerGetTimerID(params);
    (callback)(); //ejecuto el callback
}




uint8_t simo_timer_create( soft_timer_t* timer,callback_function callback, TickType_t time,uint8_t periodic)
{
    uint8_t ret = 0;
    BaseType_t _periodic;
    _periodic = (periodic == 1)? pdTRUE : pdFALSE;

    (*timer) = xTimerCreate("_SOFT_TIMER_",
                                  time,
                                 _periodic,
                                 (void*)callback,
                                 generic_handler);

    if((*timer) != NULL) ret = 1;
    return   1;
}





void simo_timer_delete(soft_timer_t* timer)
{

}



void simo_timer_start(soft_timer_t* timer)
{
  xTimerStart((*timer),0);
}


void simo_timer_stop(soft_timer_t* timer)
{
  xTimerStop((*timer),0);
}

