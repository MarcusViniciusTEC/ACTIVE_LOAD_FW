#include "hmi_menu.h"
#include "hmi_menu_types.h"

#include <stdbool.h>
#include <stdio.h>

#include "st7789.h"
#include "fonts.h"
#include "hmi.h"

/***********************************************************************************/

static void hmi_dashboard_show_voltage(void);
static void hmi_dashboard_show_power(void);
static void hmi_dashboard_show_current(void);

/***********************************************************************************/

static void hmi_dashboard_show_voltage(void)
{
    ST7789_WriteString(10, 120, "0.000 V", Font_16x26, RED, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_power(void)
{
    ST7789_WriteString(10, 60, "0.000 W", Font_16x26, YELLOW, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_current(void)
{
    ST7789_WriteString(10, 90, "0.000 A",Font_16x26, GREEN, BLACK);
}

/***********************************************************************************/

void hmi_constcurrent_init(void)
{
}

/***********************************************************************************/

void hmi_constcurrent_show_screen(void)
{
    ST7789_Fill_Color(BLACK);

    ST7789_WriteString(7, 3, "CONSTANT CURRENT", Font_16x26, WHITE, BLACK);
    ST7789_DrawLine(0, 27, 318, 27, WHITE);

    hmi_dashboard_show_voltage();
    hmi_dashboard_show_power();
    hmi_dashboard_show_current();
}

/***********************************************************************************/

void hmi_constcurrent_update_data(void)
{
    

}

/***********************************************************************************/

void hmi_constcurrent_update_button(button_id_t button_id, button_press_type_t button_press_type)
{
    switch (button_id)
    {
    case BUTTON_LEFT_ID:
        break;
    case BUTTON_RIGHT_ID:

        break;
    case BUTTON_ENC_ID:
        switch (button_press_type)
        {
        case BUTTON_SHORT_PRESS:
            hmi_set_screen(HMI_ID_SCREEN_MENU);
            break;
        case BUTTON_LONG_PRESS:
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/***********************************************************************************/

void hmi_constcurrent_update_encoder(enc_state_t enc_state)
{
    switch (enc_state)
    {
    case ENC_STATE_CCW:
        break;
    case ENC_STATE_CW:
        break;
    default:
        break;
    }

}

/***********************************************************************************/