
#include "hmi_intro.h"
#include "hmi.h"

#include "st7789.h"
#include "fonts.h"



/***********************************************************************************/

void hmi_intro_init(void)
{

}

/***********************************************************************************/

void hmi_intro_show_screen(void)
{
    ST7789_WriteString(50, 200, "INTRO", Font_16x26, DARKBLUE, BLACK);
}

/***********************************************************************************/

void hmi_intro_update_data(void)
{
    static uint32_t last_tick = 0;

    
    if(HAL_GetTick() - last_tick >= (uint32_t)TIME_EXECUTION_INTRO)
    {
        hmi_set_screen(HMI_ID_SCREEN_MENU);
    }
}

/***********************************************************************************/

void hmi_intro_update_button(button_id_t button_id, button_press_type_t button_press_type)
{

}

/***********************************************************************************/

void hmi_intro_update_encoder(enc_state_t enc_state)
{


}

/***********************************************************************************/