#ifndef __HMI_CONST_CURRENT_TYPES_H
#define __HMI_CONST_CURRENT_TYPES_H

#include "hmi_const_current_cfg.h"
#include "stdint.h"

typedef enum
{
    INDEX_FIRST_DIGIT = 0U,
    INDEX_SECOND_DIGIT,
    INDEX_THIRD_DIGIT,
    INDEX_FOURTH_DIGIT,
    INDEX_FIVE_DIGIT,
    NUMBER_OF_INDEX_DIGITS
}hmi_digit_types_t;

typedef enum
{
    MODE_CONSTANT_CURRENT = 0U,
    MODE_CONSTANT_VOLTAGE,
    MODE_CONSTANT_RESISTENCE,
    NUMBER_OF_MODES
}hmi_dashboard_mode_t;

typedef struct
{
    uint8_t value[NUMBER_OF_INDEX_DIGITS];
}hmi_edit_t;


typedef struct 
{
    hmi_dashboard_mode_t mode;
    uint8_t index_field;
    uint8_t last_index_field;
}hmi_dashboard_ctrl_t;

typedef struct 
{
    uint16_t x;
    uint16_t y;
    uint8_t last_x;
}hmi_cursor_cordinate_t;



#endif