#ifndef _ADC_H_
#define _ADC_H_

/***********************************************************************************/

#include "adc_types.h"
#include "stdint.h"

void adc_init(void);
uint32_t get_adc_raw_value(adc_mode_t mode, adc_channel_t channel);

/***********************************************************************************/

#endif
