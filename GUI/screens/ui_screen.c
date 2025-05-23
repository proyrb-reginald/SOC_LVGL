// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: soc_lvgl

#include "../ui.h"
#include "function_init.h"

extern uint8_t exKeyValue;

static lv_style_t style_button;

void touch_key_refresh_cb(lv_timer_t *timer) {
    static uint8_t last_value = 255;
    static uint8_t select = 0;

    uint8_t current_value = exKeyValue;
    lv_obj_t *select_button = NULL;
    switch (select) {
    case 0:
        select_button = ui_refreshbutton;
        break;
    case 1:
        select_button = ui_switchbutton;
        break;
    case 2:
        select_button = ui_modebutton;
        break;
    case 3:
        select_button = ui_otherbutton;
        break;
    }
    lv_obj_clear_state(select_button,
                       LV_STATE_FOCUSED); /*MAke the checkbox unchecked*/
    if ((current_value != last_value) && (current_value == 255)) {
        switch (last_value) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            select = (++select + 4) % 4;
            break;
        case 4:
            select = (--select + 4) % 4;
            break;
        default:
            break;
        }
    }
    switch (select) {
    case 0:
        select_button = ui_refreshbutton;
        break;
    case 1:
        select_button = ui_switchbutton;
        break;
    case 2:
        select_button = ui_modebutton;
        break;
    case 3:
        select_button = ui_otherbutton;
        break;
    }
    lv_obj_add_state(
        select_button,
        LV_STATE_FOCUSED); /*Make the checkbox checked and disabled*/
    last_value = current_value;
}

void ui_screen_screen_init(void) {
    lv_style_init(&style_button);
    lv_style_set_border_width(&style_button, 2);
    lv_style_set_border_color(&style_button, lv_color_hex(0xffffff));

    ui_screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_screen, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bar = lv_obj_create(ui_screen);
    lv_obj_remove_style_all(ui_bar);
    lv_obj_set_height(ui_bar, 24);
    lv_obj_set_width(ui_bar, lv_pct(100));
    lv_obj_set_align(ui_bar, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_bar,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_date = lv_label_create(ui_bar);
    lv_obj_set_width(ui_date, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_date, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_date, 8);
    lv_obj_set_y(ui_date, 0);
    lv_obj_set_align(ui_date, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_date, "2025/04/10");
    lv_obj_set_style_text_font(ui_date, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_time = lv_label_create(ui_bar);
    lv_obj_set_width(ui_time, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_time, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_time, 80);
    lv_obj_set_y(ui_time, 0);
    lv_obj_set_align(ui_time, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_time, "12:12");
    lv_obj_set_style_text_font(ui_time, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_power = lv_obj_create(ui_bar);
    lv_obj_remove_style_all(ui_power);
    lv_obj_set_width(ui_power, 50);
    lv_obj_set_height(ui_power, 24);
    lv_obj_set_align(ui_power, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_power,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_powericon = lv_bar_create(ui_power);
    lv_bar_set_value(ui_powericon, 50, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_powericon, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_powericon, 40);
    lv_obj_set_height(ui_powericon, 16);
    lv_obj_set_align(ui_powericon, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_powericon, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_powericon, lv_color_hex(0x00BA35),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_powericon, 64, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_powericon, 0,
                            LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_powericon, lv_color_hex(0x00BA35),
                              LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_powericon, 255,
                            LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_powervalue = lv_label_create(ui_power);
    lv_obj_set_width(ui_powervalue, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_powervalue, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_powervalue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_powervalue, "50%");
    lv_obj_set_style_text_font(ui_powervalue, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_chats = lv_obj_create(ui_screen);
    lv_obj_remove_style_all(ui_chats);
    lv_obj_set_height(ui_chats, 193);
    lv_obj_set_width(ui_chats, lv_pct(100));
    lv_obj_set_x(ui_chats, 0);
    lv_obj_set_y(ui_chats, 24);
    lv_obj_set_align(ui_chats, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_chats,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_temperaturecontainer = lv_obj_create(ui_chats);
    lv_obj_remove_style_all(ui_temperaturecontainer);
    lv_obj_set_height(ui_temperaturecontainer, 200);
    lv_obj_set_width(ui_temperaturecontainer, lv_pct(50));
    lv_obj_set_align(ui_temperaturecontainer, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_temperaturecontainer,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_temperature = lv_chart_create(ui_temperaturecontainer);
    lv_obj_set_width(ui_temperature, lv_pct(65));
    lv_obj_set_height(ui_temperature, lv_pct(70));
    lv_obj_set_x(ui_temperature, 15);
    lv_obj_set_y(ui_temperature, -30);
    lv_obj_set_align(ui_temperature, LV_ALIGN_BOTTOM_MID);
    lv_chart_set_type(ui_temperature, LV_CHART_TYPE_BAR);
    lv_chart_set_axis_tick(ui_temperature, LV_CHART_AXIS_PRIMARY_X, 8, 4, 5, 2,
                           true, 50);
    lv_chart_set_axis_tick(ui_temperature, LV_CHART_AXIS_PRIMARY_Y, 8, 4, 5, 2,
                           true, 50);
    lv_chart_set_axis_tick(ui_temperature, LV_CHART_AXIS_SECONDARY_Y, 8, 4, 0,
                           0, false, 25);
    lv_chart_series_t *ui_temperature_series_1 = lv_chart_add_series(
        ui_temperature, lv_color_hex(0x808080), LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_temperature_series_1_array[] = {0,  10, 20, 40, 80,
                                                         80, 40, 20, 10, 0};
    lv_chart_set_ext_y_array(ui_temperature, ui_temperature_series_1,
                             ui_temperature_series_1_array);
    lv_obj_set_style_radius(ui_temperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_temperature, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_temperature, 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_temperature, &lv_font_montserrat_12,
                               LV_PART_TICKS | LV_STATE_DEFAULT);

    ui_temperaturelabel = lv_label_create(ui_temperaturecontainer);
    lv_obj_set_width(ui_temperaturelabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_temperaturelabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_temperaturelabel, 15);
    lv_obj_set_y(ui_temperaturelabel, 10);
    lv_obj_set_align(ui_temperaturelabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_temperaturelabel, "Temperature");
    lv_obj_set_style_text_font(ui_temperaturelabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_humiditycontainer = lv_obj_create(ui_chats);
    lv_obj_remove_style_all(ui_humiditycontainer);
    lv_obj_set_height(ui_humiditycontainer, 200);
    lv_obj_set_width(ui_humiditycontainer, lv_pct(50));
    lv_obj_set_align(ui_humiditycontainer, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_humiditycontainer,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_humidity = lv_chart_create(ui_humiditycontainer);
    lv_obj_set_width(ui_humidity, lv_pct(65));
    lv_obj_set_height(ui_humidity, lv_pct(70));
    lv_obj_set_x(ui_humidity, -15);
    lv_obj_set_y(ui_humidity, -30);
    lv_obj_set_align(ui_humidity, LV_ALIGN_BOTTOM_MID);
    lv_chart_set_type(ui_humidity, LV_CHART_TYPE_LINE);
    lv_chart_set_axis_tick(ui_humidity, LV_CHART_AXIS_PRIMARY_X, 8, 4, 5, 2,
                           true, 50);
    lv_chart_set_axis_tick(ui_humidity, LV_CHART_AXIS_PRIMARY_Y, 8, 4, 0, 0,
                           false, 50);
    lv_chart_set_axis_tick(ui_humidity, LV_CHART_AXIS_SECONDARY_Y, 8, 4, 5, 2,
                           true, 25);
    lv_chart_series_t *ui_humidity_series_1 = lv_chart_add_series(
        ui_humidity, lv_color_hex(0x808080), LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_humidity_series_1_array[] = {0,  10, 20, 40, 80,
                                                      80, 40, 20, 10, 0};
    lv_chart_set_ext_y_array(ui_humidity, ui_humidity_series_1,
                             ui_humidity_series_1_array);
    lv_obj_set_style_radius(ui_humidity, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_humidity, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_humidity, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_humidity, &lv_font_montserrat_12,
                               LV_PART_TICKS | LV_STATE_DEFAULT);

    ui_humiditylabel = lv_label_create(ui_humiditycontainer);
    lv_obj_set_width(ui_humiditylabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_humiditylabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_humiditylabel, -15);
    lv_obj_set_y(ui_humiditylabel, 10);
    lv_obj_set_align(ui_humiditylabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_humiditylabel, "Humidity");
    lv_obj_set_style_text_font(ui_humiditylabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_functions = lv_obj_create(ui_screen);
    lv_obj_remove_style_all(ui_functions);
    lv_obj_set_height(ui_functions, 55);
    lv_obj_set_width(ui_functions, lv_pct(100));
    lv_obj_set_align(ui_functions, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_functions, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_functions, LV_FLEX_ALIGN_SPACE_AROUND,
                          LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_functions,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_pad_row(ui_functions, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_functions, -50,
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_refreshbutton = lv_btn_create(ui_functions);
    lv_obj_set_height(ui_refreshbutton, 30);
    lv_obj_set_width(ui_refreshbutton, lv_pct(15));
    lv_obj_set_align(ui_refreshbutton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_refreshbutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_refreshbutton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_refreshbutton, 15,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_refreshbutton, &style_button, LV_STATE_FOCUSED);

    ui_refreshlabel = lv_label_create(ui_refreshbutton);
    lv_obj_set_width(ui_refreshlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_refreshlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_refreshlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_refreshlabel, "Refresh");
    lv_obj_set_style_text_font(ui_refreshlabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_switchbutton = lv_btn_create(ui_functions);
    lv_obj_set_height(ui_switchbutton, 30);
    lv_obj_set_width(ui_switchbutton, lv_pct(15));
    lv_obj_set_align(ui_switchbutton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_switchbutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_switchbutton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_switchbutton, 15,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_switchbutton, &style_button, LV_STATE_FOCUSED);

    ui_switchlabel = lv_label_create(ui_switchbutton);
    lv_obj_set_width(ui_switchlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_switchlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_switchlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_switchlabel, "Switch");
    lv_obj_set_style_text_font(ui_switchlabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_modebutton = lv_btn_create(ui_functions);
    lv_obj_set_height(ui_modebutton, 30);
    lv_obj_set_width(ui_modebutton, lv_pct(15));
    lv_obj_set_align(ui_modebutton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_modebutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_modebutton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_modebutton, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_modebutton, &style_button, LV_STATE_FOCUSED);

    ui_modelabel = lv_label_create(ui_modebutton);
    lv_obj_set_width(ui_modelabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_modelabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_modelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_modelabel, "Mode");
    lv_obj_set_style_text_font(ui_modelabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_otherbutton = lv_btn_create(ui_functions);
    lv_obj_set_height(ui_otherbutton, 30);
    lv_obj_set_width(ui_otherbutton, lv_pct(15));
    lv_obj_set_align(ui_otherbutton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_otherbutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_otherbutton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_otherbutton, 15,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui_otherbutton, &style_button, LV_STATE_FOCUSED);

    ui_otherlabel = lv_label_create(ui_otherbutton);
    lv_obj_set_width(ui_otherlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_otherlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_otherlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_otherlabel, "Other");
    lv_obj_set_style_text_font(ui_otherlabel, &lv_font_montserrat_12,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    touch_key_refresh_timer = lv_timer_create(touch_key_refresh_cb, 10, NULL);
    lv_timer_ready(touch_key_refresh_timer);
}
