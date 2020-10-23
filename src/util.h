#ifndef SETTINGS_H
#define SETTINGS_H

/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/



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


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

uint32_t int_to_str(int32_t num, char *string, uint32_t string_size, uint8_t zero_leading, uint8_t need_minus);
uint32_t float_to_str(float num, char *string, uint32_t string_size, uint8_t precision);

void settings_screen_run(void);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
