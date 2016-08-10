#ifndef MSG_H
#define MSG_H


/*
************************************************************************************************************************
*       INCLUDE FILES
************************************************************************************************************************
*/

#include <stdint.h>


/*
************************************************************************************************************************
*       MACROS
************************************************************************************************************************
*/

#define CC_MSG_HEADER_SIZE  4


/*
************************************************************************************************************************
*       CONFIGURATION
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*       DATA TYPES
************************************************************************************************************************
*/

enum cc_cmd_t {CC_CMD_CHAIN_SYNC, CC_CMD_HANDSHAKE, CC_CMD_DEV_DESCRIPTOR, CC_CMD_ASSIGNMENT, CC_CMD_DATA_UPDATE,
               CC_CMD_UNASSIGNMENT};

typedef struct cc_msg_t {
    uint8_t dev_address;
    uint8_t command;
    uint16_t data_size;
    uint8_t *header, *data;
    uint8_t data_idx;
} cc_msg_t;


/*
************************************************************************************************************************
*       FUNCTION PROTOTYPES
************************************************************************************************************************
*/

cc_msg_t *cc_msg_new(void);

int cc_msg_parser(const cc_msg_t *msg, void *data_struct);
int cc_msg_builder(int command, const void *data_struct, cc_msg_t *msg);


/*
************************************************************************************************************************
*   CONFIGURATION ERRORS
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*   END HEADER
************************************************************************************************************************
*/

#endif
