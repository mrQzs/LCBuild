#
#Makefile
#

LVGL_DIR ?= C:/Users/root/Desktop/Work/
OBJ_DIR ?= $(LVGL_DIR)/obj

CC = arm-none-linux-gnueabi-gcc
CFLAGS ?= -w -Wshadow -Wundef -O3 -g0 -I$(LVGL_DIR)
LDFLAGS ?= -lpthread -llvgl
LDFLAGS += -L$(LVGL_DIR)/lib
CVERSION ?= -std=c99
TARGET = $(LVGL_DIR)/app

include $(LVGL_DIR)/page_1/page_1.mk

MAINSRC += $(wildcard *.c)
SRCS =  $(CSRCS) $(MAINSRC)
OBJS = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
DELOBJS = $(addprefix .\obj\,$(patsubst %.c,%.o,$(notdir $(SRCS))))

all: default

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CVERSION) $(CFLAGS) -c $< -o $@
	@echo "CC $<"

default: $(OBJS)
	$(CC) -o $(TARGET) $^ $(LDFLAGS) $(CVERSION)

.PHONY: clean
clean:
	del app
	del $(DELOBJS)
