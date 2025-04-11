/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable
 * content*/
#if 0

#include "lv_port_indev.h"
#include "../../lvgl.h"
#include "sc32f10xx_touch_key_function_resource.h"
#include "sc32f10xx_touch_key_parameter_analysis.h"

/*Initialize your keypad*/
extern uint32_t TK_exKeyValueFlag;
extern uint8_t exKeyValue;
extern uint8_t KeyValue;

static void button_init(void);
static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);

lv_indev_t *indev_button;

void lv_port_indev_init(void) {
    /**
     * Here you will find example implementation of input devices supported by
     * LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv;

    /*Initialize your button if you have*/
    button_init();

    /*Register a button input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_BUTTON;
    indev_drv.read_cb = button_read;
    indev_button = lv_indev_drv_register(&indev_drv);

    /*Assign buttons to points on the screen*/
    static const lv_point_t btn_points[4] = {
        {400, 240},
        {290, 240},
        {182, 240},
        {80, 240},
    };
    lv_indev_set_button_points(indev_button, btn_points);
}

/*Initialize your buttons*/
static void button_init(void) {
    /*Your code comes here*/
    TK_Init();
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if (btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void) {
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for (i = 0; i < 4; i++) {
        /*Return the pressed button's ID*/
        if (button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id) {

    /*Your code comes here*/
    switch (id) {
    case 0:
        if (exKeyValue == 1) {
            return LV_INDEV_STATE_PR;
        } else {
            return LV_INDEV_STATE_REL;
        }
        break;
    case 1:
        if (exKeyValue == 2) {
            return LV_INDEV_STATE_PR;
        } else {
            return LV_INDEV_STATE_REL;
        }
        break;
    case 2:
        if (exKeyValue == 3) {
            return LV_INDEV_STATE_PR;
        } else {
            return LV_INDEV_STATE_REL;
        }
        break;
    case 3:
        if (exKeyValue == 4) {
            return LV_INDEV_STATE_PR;
        } else {
            return LV_INDEV_STATE_REL;
        }
        break;
    default:
        return LV_INDEV_STATE_REL;
    }
    return false;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
