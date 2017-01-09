#ifndef HARDWARE_H
#define HARDWARE_H


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

enum {LED_R, LED_G, LED_B};
enum {LED_OFF, LED_ON, LED_TOGGLE = -1};

enum {BUTTON_RELEASED, BUTTON_PRESSED};


/*
****************************************************************************************************
*       CONFIGURATION
****************************************************************************************************
*/

#define BUTTONS_PINS    {0,7},{1,28},{0,17},{1,15}
#define LEDS_PINS       {1,21},{0, 8},{1,31},   \
                        {0, 5},{1,23},{0,21},   \
                        {0,13},{0,12},{0,14},   \
                        {1,29},{0,22},{0,11}
#define BACKLIGHTS_PINS {0,18},{1,24}

#define LCD1_PINS       {.rs = {0, 4},          \
                         .rw = {1, 20},         \
                         .en = {1, 16},         \
                         .data = {{1, 27}, {1, 26}, {0, 2}, {0, 20}}}
#define LCD2_PINS       {.rs = {0, 4},          \
                         .rw = {1, 20},         \
                         .en = {0, 19},         \
                         .data = {{1, 27}, {1, 26}, {0, 2}, {0, 20}}}

#define BUTTON_DEBOUNCE 10


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

void hw_init(void);
int hw_button(int button);
void hw_led(int led, int color, int value);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
