/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

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
    // FIXME: it's hardcoded because should have only one call to this function
    static cc_handshake_t s_handshake;

    cc_handshake_t *handshake = &s_handshake;

    // uri
    handshake->uri = uri;

    // TODO: generate random number
    handshake->random_id = 0xABCD;

    // protocol version
    handshake->protocol.major = 0;
    handshake->protocol.minor = 0;
    handshake->protocol.micro = 0;

    // firmware version
    handshake->firmware.major = 0;
    handshake->firmware.minor = 0;
    handshake->firmware.micro = 0;

    return handshake;
}
