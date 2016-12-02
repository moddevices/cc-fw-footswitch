#ifndef SERIAL_H
#define SERIAL_H

/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include <stdint.h>


/*
****************************************************************************************************
*       MACROS
****************************************************************************************************
*/


/*
****************************************************************************************************
*       CONFIGURATION
****************************************************************************************************
*/


/*
****************************************************************************************************
*       DATA TYPES
****************************************************************************************************
*/

typedef struct serial_t serial_t;

typedef struct serial_data_t {
    uint8_t *data;
    uint32_t size;
} serial_data_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

serial_t *serial_init(uint32_t baud_rate, void (*receive_cb)(void *arg));
void serial_send(serial_t *serial, serial_data_t *sdata);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
