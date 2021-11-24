/**
 * @file wdt.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief 
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _SIMO_TIMER_WDT_H
#define _SIMO_TIMER_WDT_H


/**
 * @brief Iniciamos una tarea encargada de gestionar el wdt.
 *  Esta tarea tiene una prioridad alta y debe tenerse en cuenta a la hora de diseñar la aplicacion 
 * 
 * @return ** void 
 */
    void simo_wdt_init(void);


  /**
   * @brief Desactivamos el wdt
   * 
   * @return ** void 
   */
    void simo_wdt_deinit(void);




    /**
     * @brief Reiniciamos contador del wdt
     * 
     * @return ** void 
     */
    void simo_wdt_reset(void);


#endif

