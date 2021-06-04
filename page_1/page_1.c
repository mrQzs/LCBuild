#include "page_1.h"
#include "app.h"

/**********************
 *       WIDGETS
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/


lv_obj_t* button_1_ev_0;
lv_obj_t* button_2_ev_0;

lv_obj_t* page_1_create(){
	lv_obj_t *parent = lv_obj_create(NULL, NULL);

	static lv_style_t button_1_s0;
	lv_style_init(&button_1_s0);
	lv_style_set_value_font(&button_1_s0,LV_STATE_DEFAULT,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_CHECKED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_FOCUSED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_EDITED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_HOVERED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_PRESSED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_1_s0,LV_STATE_DISABLED,&lv_font_123abc_16);
	lv_obj_t *button_1 = lv_btn_create(parent, NULL);
	lv_obj_add_style(button_1, 0, &button_1_s0);
	lv_obj_set_hidden(button_1, false);
	lv_obj_set_click(button_1, true);
	lv_obj_set_drag(button_1, false);
	lv_obj_set_pos(button_1, 237, 153);
	lv_obj_set_size(button_1, 100, 35);
	lv_btn_set_checkable(button_1, false);
	lv_btn_set_fit(button_1, LV_FIT_NONE);

	button_1_ev_0 = button_1;


	static lv_style_t button_2_s0;
	lv_style_init(&button_2_s0);
	lv_style_set_value_font(&button_2_s0,LV_STATE_DEFAULT,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_CHECKED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_FOCUSED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_EDITED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_HOVERED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_PRESSED,&lv_font_123abc_16);
	lv_style_set_value_font(&button_2_s0,LV_STATE_DISABLED,&lv_font_123abc_16);
	lv_obj_t *button_2 = lv_btn_create(parent, NULL);
	lv_obj_add_style(button_2, 0, &button_2_s0);
	lv_obj_set_hidden(button_2, false);
	lv_obj_set_click(button_2, true);
	lv_obj_set_drag(button_2, false);
	lv_obj_set_pos(button_2, 111, 266);
	lv_obj_set_size(button_2, 100, 35);
	lv_btn_set_checkable(button_2, false);
	lv_btn_set_fit(button_2, LV_FIT_NONE);

	button_2_ev_0 = button_2;


	return parent;
}
