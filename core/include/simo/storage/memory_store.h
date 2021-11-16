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
 * @param len   tamanio de los datos. Maximo 256. (Cada datos tiene su propia pagina)
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


uint16_t _get_counter();




void simo_memory_store_full_clear();



uint16_t simo_memory_read_all(print_funcion fun);

void _set_counter(uint16_t count);
