CSRCS += lv_font_123abc_16.c

DEPPATH += --dep-path $(LVGL_DIR)/page_1/fonts
VPATH += :$(LVGL_DIR)/page_1/fonts

CFLAGS += "-I$(LVGL_DIR)/page_1/fonts"
