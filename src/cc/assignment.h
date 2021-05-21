#ifndef CC_ASSIGNMENT_H
#define CC_ASSIGNMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include <stdint.h>
#include "utils.h"


/*
****************************************************************************************************
*       MACROS
****************************************************************************************************
*/

#define CC_MODE_TOGGLE      0x001
#define CC_MODE_TRIGGER     0x002
#define CC_MODE_OPTIONS     0x004
#define CC_MODE_TAP_TEMPO   0x008
#define CC_MODE_REAL        0x010
#define CC_MODE_INTEGER     0x020
#define CC_MODE_LOGARITHMIC 0x040
#define CC_MODE_COLOURED    0x100
#define CC_MODE_MOMENTARY   0x200


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

typedef struct cc_assignment_t {
    int id, actuator_id;
    float value, min, max, def;
    uint32_t mode;
    uint16_t steps;
    uint8_t list_count;
#ifndef CC_STRING_NOT_SUPPORTED
    uint8_t list_index;
    option_t **list_items;
    str16_t label, unit;
#endif
} cc_assignment_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

// create a new assignment
cc_assignment_t *cc_assignment_new(void);
// delete an assignment
int cc_assignment_delete(int assignment_id);
// get the assignment with a specific id (can return null)
cc_assignment_t *cc_assignment_get(int assignment_id);
// remove all assignments
void cc_assignments_clear(void);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/

#ifdef __cplusplus
}
#endif

#endif
