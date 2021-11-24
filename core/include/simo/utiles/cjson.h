/**
 * @file cjson.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "simo/core.h"

typedef struct 
{
    //! puntero a el array de datos formateado en json
    char* p_string;
    //! index
    uint32_t index;
    //tamanio maximo del string
    uint32_t len;

}cjson_t;


/**
 * @brief Crea un objeto json con un array de char (string)
 * 
 * @param len  tamanio del array asociado
 * @return ** cjson_t* 
 */
cjson_t* simo_cjson_create(uint32_t len);


/**
 * @brief 
 * 
 * @param cjson 
 * @param key 
 * @param element 
 * @return ** uint8_t 
 */
uint8_t simo_cjson_add_int(cjson_t* cjson,char* key, int32_t element);
/**
 * @brief  Agregamos un elemento al json
 * 
 * @param cjson 
 * @param key 
 * @param element 
 * @return ** uint8_t 
 */
uint8_t simo_cjson_add_float(cjson_t* cjson,char* key, float element);

/**
 * @brief  Agregamos un elemento al json
 * 
 * @param cjson 
 * @param key 
 * @param element 
 * @return ** uint8_t 
 */

uint8_t simo_cjson_add_string(cjson_t* cjson,char* key, char* element);

/**
 * @brief  Agregamos un elemento al json
 * 
 * @param cjson 
 * @return ** void 
 */

void simo_cjson_delete(cjson_t* cjson);

/**
 * @brief  Objetemos el array con los datos del json
 * 
 * @param cjson 
 * @return ** char* 
 */

char* simo_cjson_get_string(cjson_t* cjson);


/**
 * @brief 
 * 
 * @param cjson 
 * @param key 
 * @param element 
 * @return ** uint8_t 
 */
uint8_t simo_cjson_add_uint(cjson_t* cjson,char* key, uint32_t element);


