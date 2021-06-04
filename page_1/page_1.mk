include $(LVGL_DIR)/page_1/images/page_1_images.mk
include $(LVGL_DIR)/page_1/fonts/page_1_fonts.mk

CSRCS += page_1.c

DEPPATH += --dep-path $(LVGL_DIR)/page_1
VPATH += :$(LVGL_DIR)/page_1

CFLAGS += "-I$(LVGL_DIR)/page_1"
