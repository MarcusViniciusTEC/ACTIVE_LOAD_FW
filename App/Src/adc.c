

#include "adc.h"
#include "adc_types.h"
#include "ADS1015_ADS1115.h"

/***********************************************************************************/

ADS1xx5_I2C adc[NUMBER_OF_MODULES_ADC];

/***********************************************************************************/

void adc_init(void);
uint32_t get_adc_raw_value(adc_mode_t mode, adc_channel_t channel);

/***********************************************************************************/

void adc_init(void)
{
    for(uint8_t index  = 0; index < NUMBER_OF_MODULES_ADC; index++)
    {
        ADS1115(&adc[index], &hi2c1, ADS_ADDR_GND);
        ADSsetGain(&adc[index], GAIN_ONE);
    }
}

/***********************************************************************************/

uint32_t get_adc_raw_value(adc_mode_t mode, adc_channel_t channel)
{
    return ADSreadADC_SingleEnded(&adc[mode], channel);
}

/***********************************************************************************/


