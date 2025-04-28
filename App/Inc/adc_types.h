#ifndef _ADC_TYPES_H_
#define _ADC_TYPES_H_


#include "adc_cfg.h"


typedef enum
{
    ADC_MODE_CURRENT = 0U,
    ADC_MODE_VOLTAGE,
    ADC_MODE_TEMPERATURE
}adc_mode_t;

typedef enum
{
    CURRENT_CHANNEL_0 = 0U,
    CURRENT_CHANNEL_1, 
    CURRENT_CHANNEL_2, 
    CURRENT_CHANNEL_4, 
}adc_channel_t;

#endif
