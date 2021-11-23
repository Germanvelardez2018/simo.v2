/**
 * @file cjson.c
 * @author your name (you@domain.com)
 * @brief  Nueva implementacion del json para microcontroladores
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "simo/core.h"
#include "simo/utiles/cjson.h"




#define ADD_CJSON_UINT      "%c %s : %u \r\n "
#define ADD_CJSON_INT       "%c %s : %d \r\n "
#define ADD_CJSON_FLOAT     "%c %s : %.2f \r\n "
#define ADD_CJSON_STRING    "%c %s : %s \r\n "
#define INIT_CONTENT       "\r\n{ }" 
#define INIT_LEN            6


cjson_t* simo_cjson_create(uint32_t len)
{


    cjson_t* cjson = (cjson_t*) malloc(sizeof(cjson_t));

    if(cjson == NULL) return NULL;

   
    cjson->p_string = (char*) malloc(sizeof(char)*len);
    if (cjson->p_string == NULL) return NULL;
    cjson->index=0;
    strcpy(cjson->p_string,INIT_CONTENT);   //INIT_LEN
    cjson->index = strlen(cjson->p_string);
    return cjson;
}


uint8_t simo_cjson_add_int(cjson_t* cjson,char* key, uint32_t element)
{
    uint32_t index = cjson->index;
    sprintf(&(cjson->p_string[index-1]), ADD_CJSON_FLOAT,((cjson->index<INIT_LEN)?'\n':','),key,element);
    cjson->index = strlen(cjson->p_string);

    

    return 1;
}

uint8_t simo_cjson_add_float(cjson_t* cjson,char* key, float element)
{
    uint32_t index = cjson->index;
    sprintf(&(cjson->p_string[index-1]), ADD_CJSON_FLOAT,((cjson->index<5)?'\n':','),key,element);
    cjson->index = strlen(cjson->p_string);

    return 1;
}

uint8_t simo_cjson_add_string(cjson_t* cjson,char* key, char* element)
{
    uint32_t index = cjson->index;
    sprintf(&(cjson->p_string[index-1]), ADD_CJSON_STRING,((cjson->index<5)?'\n':','),key,element);
    cjson->index = strlen(cjson->p_string);

    return 1;
}


char* simo_cjson_get_string(cjson_t* cjson)
{
     uint32_t index = cjson->index;
    sprintf(&(cjson->p_string[index-1]),"}");
    cjson->index = strlen(cjson->p_string);
    return cjson->p_string;
}



void simo_cjson_delete(cjson_t* cjson)
{
    if(cjson != NULL)
    {
        free(cjson->p_string);
        free(cjson);
    }
}