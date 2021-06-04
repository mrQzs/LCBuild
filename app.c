#include "app.h"

#include <stdlib.h>


#include "page_1/page_1.h"

static lv_obj_t *page_1;


void app(){
	page_1 = page_1_create();

	lv_scr_load(page_1);
}