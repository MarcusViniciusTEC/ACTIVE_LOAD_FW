#include "hmi_menu.h"
#include "hmi_menu_types.h"

#include <stdbool.h>
#include <stdio.h>

#include "st7789.h"
#include "fonts.h"
#include "hmi.h"

#include "hmi_const_current_types.h"

static hmi_edit_t hmi_edit[NUMBER_OF_MODES] = {0};
static hmi_dashboard_ctrl_t hmi_dashboard_ctrl = {0};
static hmi_cursor_cordinate_t hmi_cursor_cordinate[5] = cursor_cordinate_default;

/***********************************************************************************/

static void hmi_dashboard_show_voltage(void);
static void hmi_dashboard_show_power(void);
static void hmi_dashboard_show_current(void);
static void hmi_dashboard_show_temp(void);
static void hmi_dashboard_show_time(void);
static void hmi_dashboard_show_resistence(void);
static void hmi_dashboard_show_out_status(void);
static void hmi_dashboard_show_target_current(void);
static void hmi_dashboard_show_cursor(void);

/***********************************************************************************/

static void hmi_dashboard_show_current(void)
{
    ST7789_WriteString(5, 30, "Read:",Font_11x18, LIGHTBLUE, BLACK);
    ST7789_WriteString(5, 50, "00.000 A",Font_16x26, GREEN, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_voltage(void)
{
    ST7789_WriteString(5, 80, "23.100 V", Font_16x26, RED, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_power(void)
{
    ST7789_WriteString(5, 110, "00.000 W", Font_16x26, YELLOW, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_resistence(void)
{
    ST7789_WriteString(5, 140, "00.000 R",Font_16x26, GRAY, BLACK);   
}

/***********************************************************************************/

static void hmi_dashboard_show_temp(void)
{
    ST7789_WriteString(143, 110, "Temp: 30.5'C",Font_11x18, MAGENTA, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_time(void)
{
    ST7789_WriteString(143, 130, "Time: 10:23:12",Font_11x18, MAGENTA, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_out_status(void)
{
    ST7789_WriteString(143, 150, "OUT:",Font_16x26, MAGENTA, BLACK);
    ST7789_WriteString(215, 150, "OFF!",Font_16x26, RED, BLACK);
}

/***********************************************************************************/

static void hmi_dashboard_show_target_current(void)
{
    ST7789_WriteString(143, 30, "Target:",Font_11x18, LIGHTBLUE, BLACK);

    char sz_string[20] = {0};
    snprintf(sz_string, sizeof(sz_string), "%u%u.%u%u%u A",
    hmi_edit[hmi_dashboard_ctrl.mode].value[INDEX_FIRST_DIGIT],
    hmi_edit[hmi_dashboard_ctrl.mode].value[INDEX_SECOND_DIGIT],
    hmi_edit[hmi_dashboard_ctrl.mode].value[INDEX_THIRD_DIGIT],
    hmi_edit[hmi_dashboard_ctrl.mode].value[INDEX_FOURTH_DIGIT],
    hmi_edit[hmi_dashboard_ctrl.mode].value[INDEX_FIVE_DIGIT]);

    ST7789_WriteString(143, 50, sz_string, Font_16x26, GREEN, BLACK);
}


/***********************************************************************************/

static void hmi_dashboard_show_cursor(void)
{
    hmi_cursor_cordinate_t cursor;
    cursor = hmi_cursor_cordinate[hmi_dashboard_ctrl.index_field];
    ST7789_WriteString(cursor.x, cursor.y, "^",Font_11x18, GREEN, BLACK);

    if(hmi_dashboard_ctrl.index_field !=  hmi_dashboard_ctrl.last_index_field)
    {
        cursor = hmi_cursor_cordinate[hmi_dashboard_ctrl.last_index_field];
        ST7789_WriteString(cursor.x, cursor.y, " ",Font_11x18, GREEN, BLACK);

        hmi_dashboard_ctrl.last_index_field = hmi_dashboard_ctrl.index_field;
    }
}

/***********************************************************************************/

void hmi_constcurrent_init(void)
{
    hmi_dashboard_ctrl.index_field = INDEX_FIRST_DIGIT;
    hmi_dashboard_ctrl.last_index_field = hmi_dashboard_ctrl.index_field;

    hmi_dashboard_ctrl.mode = MODE_CONSTANT_CURRENT;
}

/***********************************************************************************/

void hmi_constcurrent_show_screen(void)
{
    ST7789_Fill_Color(BLACK);

    ST7789_WriteString(19, 3, "CONSTANT CURRENT", Font_16x26, WHITE, BLACK);
    ST7789_DrawLine(0, 27, 318, 27, WHITE);
    ST7789_DrawLine(0, 180, 318, 180, WHITE);
    ST7789_WriteString(12, 200, "ABL Solutions Ind", Font_16x26, BLUE, BLACK);
    ST7789_DrawRectangle(0, 0, 318, 239, WHITE);
    ST7789_DrawLine(137, 27, 137, 180, WHITE);
    ST7789_DrawLine(137, 100, 318, 100, WHITE);

    hmi_dashboard_show_voltage();
    hmi_dashboard_show_power();
    hmi_dashboard_show_current();
    hmi_dashboard_show_temp();
    hmi_dashboard_show_time();
    hmi_dashboard_show_out_status();
    hmi_dashboard_show_target_current();
    hmi_dashboard_show_resistence();
    hmi_dashboard_show_cursor();
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
        hmi_dashboard_ctrl.index_field--;
        break;
    case BUTTON_RIGHT_ID:
        hmi_dashboard_ctrl.index_field++;
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

    hmi_dashboard_show_cursor();
}

/***********************************************************************************/

void hmi_constcurrent_update_encoder(enc_state_t enc_state)
{
    switch (enc_state)
    {
    case ENC_STATE_CCW:

        hmi_edit[hmi_dashboard_ctrl.mode].value[hmi_dashboard_ctrl.index_field]++;
        break;
    case ENC_STATE_CW:
        hmi_edit[hmi_dashboard_ctrl.mode].value[hmi_dashboard_ctrl.index_field]--;
        break;
    default:
        break;
    }
    hmi_dashboard_show_target_current();
}

/***********************************************************************************/