/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"

#include "app.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *kb_indev;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  lv_init();
  hal_init();

  app();
  
  while (1) {
    lv_task_handler();
    usleep(5 * 1000);
    lv_tick_inc(5);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics
 * library
 */
static void hal_init(void) {
  fbdev_init();

  static lv_disp_buf_t disp_buf;
  static lv_color_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX/10];                     /*Declare a buffer for 1/10 screen size*/
  lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX/10);    /*Initialize the display buffer*/

  /*Create a display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.buffer = &disp_buf;
  disp_drv.flush_cb = fbdev_flush;
  disp_drv.hor_res = LV_HOR_RES_MAX;
  disp_drv.ver_res = LV_VER_RES_MAX;
  //disp_drv.sw_rotate= 1;
  lv_disp_drv_register(&disp_drv);
  //lv_disp_set_rotation(dip, LV_DISP_ROT_90);


  evdev_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = evdev_read;
  lv_indev_drv_register(&indev_drv);
}
