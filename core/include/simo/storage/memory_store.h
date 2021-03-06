/**
 * @file memory_store.h
 * @author German Velardez (gvelardez@inti.gob.ar)
 * @brief   Driver para memory
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "simo/core.h"
/**
 * @brief funcion print
 * @note  
 * 
 */

typedef void(*print_funcion)(char*);




/**
 * @brief Inicio la memoria
 * 
 * @return true 
 * @return false 
 */
bool simo_memory_store_init(void);

/**
 * @brief  Termino la memoria
 * 
 * @return ** void 
 */
void simo_memory_store_deinit(void);


/**
 * @brief  Agrego datos en la memoria. Los datos se agregan a partir de la posicion OFFSETDATA
 * 
 * @param data  datos a enviar
 * @param len   tamanio de los datos. Maximo 254. 
 * @return ** uint16_t 
 */
uint16_t simo_memory_store_add_page(char* data, uint8_t len);



/**
 * @brief Indico la pagina en la que quiero leer datos. Retorna true si esa pagina tiene datos validos
 * 
 * @param buffer buffer para guardar datos leidos
 * @param len    tamanio del buffer
 * @param index  pagina a leer
 * @return true 
 * @return false 
 */
bool simo_memory_store_read_page(uint8_t* buffer,uint8_t len,uint16_t index);


/**
 * @brief Ejecuta la secuencia de borrado de la memoria
 * 
 * @param delay_rtos funcion para retardos de rtos. Necesaria porque el borrado lleva bastante tiempo
 * @return ** void 
 */
void simo_memory_store_full_clear(delay_rtos delay_rtos);



/**
 * @brief Lee todos los datos de la memoria y 
 * los imprime con la funcion de impresion que se pasa por parametros. 
 * Esta funcion podria ser una funcion que envie los datos por mqtt
 * @param fun 
 * @param delay_rtos 
 * @return ** uint16_t 
 */
uint16_t simo_memory_read_all(print_funcion fun,delay_rtos delay_rtos );




/**
 * @brief Ponemos a cero el contador de datos almacenados. 
 * @note Deberia ser antecedido por la funcion simo_memory_store_full_clear()
 * 
 * @return ** void 
 */
void simo_memory_store_clear_counter();


