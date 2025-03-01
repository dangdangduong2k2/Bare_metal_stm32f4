PRO_DIR := .
PRO_NAME := stm32_f4

OUTPUT_DIR := $(PRO_DIR)/output

INC_DIR := $(PRO_DIR)/../0.application
INC_DIR += $(PRO_DIR)/../1.driver
INC_DIR += $(PRO_DIR)/../1.driver/1.peripheral_driver/0.clock
INC_DIR += $(PRO_DIR)/../1.driver/1.peripheral_driver/1.gpio
INC_DIR += $(PRO_DIR)/../1.driver/0.user_driver/0.delay
INC_DIR += $(PRO_DIR)/../2.system

SRC_DIR := $(PRO_DIR)/../0.application
SRC_DIR += $(PRO_DIR)/../1.driver
SRC_DIR += $(PRO_DIR)/../1.driver/1.peripheral_driver/0.clock
SRC_DIR += $(PRO_DIR)/../1.driver/1.peripheral_driver/1.gpio
SRC_DIR += $(PRO_DIR)/../1.driver/0.user_driver/0.delay
SRC_DIR += $(PRO_DIR)/../2.system/1.startup


SRC_FILES := $(foreach SRC_DIR,$(SRC_DIR),$(wildcard $(SRC_DIR)/*.c))
INC_FILES := $(foreach INC_DIR,$(INC_DIR),$(wildcard $(INC_DIR)/*.h))
INC_FILES := $(notdir $(INC_FILES))
COMPILER_DIR := C:/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi

LINKER = $(PRO_DIR)/../2.system/0.linker/linker_stm32f4.ld

CC := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
LD := $(COMPILER_DIR)/bin/arm-none-eabi-ld 

INC_DIR_OPT := $(foreach INC_DIR,$(INC_DIR),-I$(INC_DIR))

CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mfloat-abi=soft -std=gnu11 -mthumb $(INC_DIR_OPT)
LD_OPT := -T $(LINKER) -Map $(OUTPUT_DIR)/$(PRO_NAME).map 

OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))

PATH_OBJ := $(foreach OBJ_FILES , $(OBJ_FILES), $(OUTPUT_DIR)/$(OBJ_FILES))

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

build: $(OBJ_FILES) $(LINKER)
	$(LD) $(LD_OPT) $(PATH_OBJ) -o $(OUTPUT_DIR)/$(PRO_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(OUTPUT_DIR)/$(PRO_NAME).elf" "$(OUTPUT_DIR)/$(PRO_NAME).hex"
	@echo "------------------build done-----------------"

%.o: %.c $(INC_FILES)
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CC_OPT) -c $< -o $(OUTPUT_DIR)/$@ 

upload: 
	$(PRO_DIR)/ST_LINK_Utility/ST-LINK_CLI.exe -p "$(OUTPUT_DIR)/$(PRO_NAME).hex" 0x08000000 -Rst
	@echo "------------------flash done-----------------"

# BL: clear $(OBJ_FILES) $(LINKER)
# 	mkdir -p $(OUTPUT_DIR)
# 	$(LD) $(LD_OPT) $(PATH_OBJ) -o $(OUTPUT_DIR)/$(PRO_NAME).elf
# 	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(OUTPUT_DIR)/$(PRO_NAME).elf" "$(OUTPUT_DIR)/$(PRO_NAME).hex"
# 	@echo "------------------build done-----------------"
# 	$(PRO_DIR)/ST_LINK_Utility/ST-LINK_CLI.exe -p "$(OUTPUT_DIR)/$(PRO_NAME).hex" 0x08000000
# 	$(PRO_DIR)/ST_LINK_Utility/ST-LINK_CLI.exe -rst
# 	@echo "------------------flash done-----------------"
BL: build upload

%.o: %.c $(INC_FILES)
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CC_OPT) -c $< -o $(OUTPUT_DIR)/$@ 

.PHONY: clear
clear:
	rm -rf $(OUTPUT_DIR)





