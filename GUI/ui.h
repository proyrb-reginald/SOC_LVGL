// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: test_fps

#ifndef _TEST_FPS_UI_H
#define _TEST_FPS_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#include "ui_events.h"
#include "ui_helpers.h"

// #define Container_Size 32
// #define Container_Size 52
#define Container_Size 72
// #define Container_Size 92
// #define Container_Size 112
// #define Container_Size 132
// #define Container_Size 152
// #define Container_Size 172
// #define Container_Size 192
// #define Container_Size 212
// #define Container_Size 232
// #define Container_Size 252
// #define Container_Size 272

#define Image_Size 200
#define Image_File background_200

LV_IMG_DECLARE(Image_File);

void HorizontalMovement_Animation(lv_obj_t *TargetObject, int delay);

// SCREEN: ui_Screen
void ui_Screen_screen_init(void);
extern lv_obj_t *ui_Screen;
extern lv_obj_t *ui_Container;
extern lv_obj_t *ui_Image;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t *ui____initial_actions0;

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
