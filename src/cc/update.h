#ifndef CC_UPDATE_H
#define CC_UPDATE_H


/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include <stdint.h>
#include "lili.h"


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

typedef lili_t cc_updates_t;

typedef struct cc_update_t {
    int id;
    int assignment_id;
    float value;
} cc_update_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

void cc_update_push(const cc_update_t *update);
int cc_update_pop(cc_update_t *update);
cc_updates_t *cc_updates(void);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
