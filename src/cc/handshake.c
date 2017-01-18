/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include "control_chain.h"
#include "handshake.h"


/*
****************************************************************************************************
*       INTERNAL MACROS
****************************************************************************************************
*/


/*
****************************************************************************************************
*       INTERNAL CONSTANTS
****************************************************************************************************
*/


/*
****************************************************************************************************
*       INTERNAL DATA TYPES
****************************************************************************************************
*/


/*
****************************************************************************************************
*       INTERNAL GLOBAL VARIABLES
****************************************************************************************************
*/

static cc_handshake_t g_handshake;


/*
****************************************************************************************************
*       INTERNAL FUNCTIONS
****************************************************************************************************
*/


/*
****************************************************************************************************
*       GLOBAL FUNCTIONS
****************************************************************************************************
*/

cc_handshake_t *cc_handshake_generate(string_t *uri)
{
    cc_handshake_t *handshake = &g_handshake;

    // uri
    handshake->uri = uri;

    // TODO: generate random number
    handshake->random_id = 0xABCD;

    // protocol version
    handshake->protocol.major = CC_PROTOCOL_MAJOR;
    handshake->protocol.minor = CC_PROTOCOL_MINOR;
    handshake->protocol.micro = 0;

    // firmware version
    handshake->firmware.major = 0;
    handshake->firmware.minor = 0;
    handshake->firmware.micro = 0;

    return handshake;
}

void cc_handshake_callback(void (*handshake_cb)(void *arg))
{
    g_handshake.callback = handshake_cb;
}
