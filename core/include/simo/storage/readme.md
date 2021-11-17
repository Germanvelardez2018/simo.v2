### Sistema de almacenamiento de datos del SIMO: memory_store.h



 ####  Memoria flash utilizada: at45db041E
 ###### PAGINAS: 2048        DIRECCION DE 11 BITS
 ###### BLOQUES: 256         DIRECCION DE 8 BITS
 ###### SECTORES: 8  
 
 ##### Formato de datos almacenados
 ##### |CHAR_INIT_SIMO| TAMANIO DEL STRING|STRING|
 ###### Datasheet: [Link](https://github.com/Germanvelardez2018/simo.v2/blob/master/core/include/simo/storage/Datasheets/AT45DB041E.pdf)
 
Estan diseñados para almacenar datos en formato char* de 254 bytes de longitud maxima.
Utilizan un formato de 2 bytes iniciales que le permite a las funciones de lectura saber si un datos es valido y cuantos bytes reales ocupa.
```c  
#include "simo/storage/memory_store.h" // Incluimos memory_store.h

#define N_PAGES                 2048   // Cantidad de paginas(256bytes disponibles)
#define SIZE_PAGE               256     //Tamanio en bytes de las paginas
#define ADDRES_COUNTER          10     //Direccion donde se encuentra el contador de datos

#define DATA_OFFSET             48   //2000 DATOS PARA ALMACENAR
#define MAX_DATA                2000

#define CHAR_INIT_SIMO          0x11  Si no se detecta este caracter el string es invalido y se descarta
#define MAX_LEN_STRING          254  // Tamanio maximo de los string a almacenar
|
```
#### Principales funciones

```c  
#include "simo/storage/memory_store.h" // Incluimos memory_store.h

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
 * @brief  Ejecuta la secuenca de borrado de la memoria completa
 * 
 * @return ** void 
 */
void simo_memory_store_full_clear();


/**
 * @brief  Agrego datos en la memoria. Los datos se agregan a partir de la posicion OFFSETDATA
 * 
 * @param data  datos a enviar
 * @param len   tamanio de los datos. Maximo 254.
 * @return ** uint16_t 
 */
uint16_t simo_memory_store_add_page(char* data, uint8_t len);




/**
 * @brief  Lee todos los datos de la memoria y 
 * los imprime con la funcion de impresion que se pasa por parametros. Esta funcion podria ser una funcion que envie los datos por mqtt
 * 
 * @param fun  es un puntero a funcion que recibe char* como parametro y devuelve void.
 * @return ** uint16_t 
 */
uint16_t simo_memory_read_all(print_funcion fun);
|
```