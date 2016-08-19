/*
************************************************************************************************************************
*       INCLUDE FILES
************************************************************************************************************************
*/

#include "actuator.h"
#include "update.h"
#include <math.h>


/*
************************************************************************************************************************
*       INTERNAL MACROS
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*       INTERNAL CONSTANTS
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*       INTERNAL DATA TYPES
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*       INTERNAL GLOBAL VARIABLES
************************************************************************************************************************
*/

static cc_actuators_t *g_actuators = 0;
static unsigned int g_actuators_count;


/*
************************************************************************************************************************
*       INTERNAL FUNCTIONS
************************************************************************************************************************
*/

static int assignment_update(cc_actuator_t *actuator, cc_assignment_t *assignment)
{
    float a, b;
    a = (assignment->max - assignment->min) / (actuator->max - actuator->min);
    b = assignment->min - a*actuator->min;

    float value, actuator_value = *(actuator->value);
    value = a*actuator_value + b;

    if (abs(assignment->value - value) >= 0.0001)
    {
        assignment->value = value;
        return 1;
    }

    return 0;
}


/*
************************************************************************************************************************
*       GLOBAL FUNCTIONS
************************************************************************************************************************
*/

cc_actuator_t *cc_actuator_new(volatile float *var)
{
    if (!g_actuators)
        g_actuators = node_create(0);

    cc_actuator_t *actuator = (cc_actuator_t *) malloc(sizeof (cc_actuator_t));

    // initialize actuator data struct
    actuator->id = g_actuators_count++;
    actuator->assignment = 0;

    // FIXME: for initial tests
    actuator->min = 0.0;
    actuator->max = 1.0;
    actuator->value = var;

    // append new actuator to actuators list
    node_child(g_actuators, actuator);

    return actuator;
}

void cc_actuator_map(cc_assignment_t *assignment)
{
    cc_actuators_t *actuators;
    for (actuators = cc_actuators(); actuators; actuators = actuators->next)
    {
        cc_actuator_t *actuator = actuators->data;
        if (actuator->id == assignment->actuator_id)
        {
            actuator->assignment = assignment;
            break;
        }
    }
}

cc_actuators_t *cc_actuators(void)
{
    if (g_actuators)
        return g_actuators->first;

    return 0;
}

void cc_actuators_process(void)
{
    cc_actuators_t *actuators;
    for (actuators = cc_actuators(); actuators; actuators = actuators->next)
    {
        cc_actuator_t *actuator = actuators->data;
        cc_assignment_t *assignment = actuator->assignment;

        if (!assignment)
            continue;

        // update assignment value according current actuator value
        int updated = assignment_update(actuator, assignment);

        if (updated)
        {
            // append update to be sent
            cc_update_t update;
            update.assignment_id = assignment->id;
            update.value = assignment->value;
            cc_update_append(&update);
        }
    }
}
