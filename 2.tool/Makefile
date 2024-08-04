PRO_DIR := .
PRO_NAME := stm32_f4

OUTPUT_DIR := $(PRO_DIR)/output

INC_DIR := $(PRO_DIR)/../0.application

INC_DIR += $(PRO_DIR)/../2.tool/0.system

SRC_DIR := $(PRO_DIR)/../0.application

SRC_DIR += $(PRO_DIR)/../2.tool/0.system
SRC_DIR += $(PRO_DIR)/../2.tool/2.startup

SRC_FILES := $(foreach SRC_DIR,$(SRC_DIR),$(wildcard $(SRC_DIR)/*.c))
INC_FILES := $(foreach INC_DIR,$(INC_DIR),$(wildcard $(INC_DIR)/*.h))

COMPILER_DIR := C:/arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi

LINKER = $(PRO_DIR)/1.linker/STM32F407VETx_FLASH.ld

CC := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
LD := $(COMPILER_DIR)/bin/arm-none-eabi-ld 

LIB_PATH += -L$(COMPILER_DIR)/arm-none-eabi/lib/thumb/v6-m/nofp
LIB_PATH += -L$(COMPILER_DIR)/lib/gcc/arm-none-eabi/10.3.1/thumb/v6-m/nofp

LIBC := $(COMPILER_DIR)/arm-none-eabi/lib/thumb/v6-m/nofp/libc.a

INC_DIR_OPT := $(foreach INC_DIR,$(INC_DIR),-I$(INC_DIR))

CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mfloat-abi=soft -std=gnu11 -mthumb $(INC_DIR_OPT)
LD_OPT :=-T $(LINKER) -Map $(OUTPUT_DIR)/$(PRO_NAME).map $(LIBC)

LDFLAGS	=	-Map=$(OUTPUT_DIR)/$(PRO_NAME).map	\
		--gc-sections	\
		$(LIB_PATH)	\
		$(LIBC) 

OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))

PATH_OBJ := $(foreach OBJ_FILES , $(OBJ_FILES), $(OUTPUT_DIR)/$(OBJ_FILES))

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

build: $(OBJ_FILES) $(LINKER)
	$(LD) $(LDFLAGS) $(PATH_OBJ) -o $(OUTPUT_DIR)/$(PRO_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(OUTPUT_DIR)/$(PRO_NAME).elf" "$(OUTPUT_DIR)/$(PRO_NAME).hex"
	@echo "------------------build done-----------------"

%.o: %.c $(INC_FILES)
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CC_OPT) -c $< -o $(OUTPUT_DIR)/$@ 

upload: 
	$(PRO_DIR)/ST_LINK_Utility/ST-LINK_CLI.exe -p "$(OUTPUT_DIR)/$(PRO_NAME).hex" 0x08000000
	$(PRO_DIR)/ST_LINK_Utility/ST-LINK_CLI.exe -rst


.PHONY: clear 
clear:
	rm -rf $(OUTPUT_DIR)
log-%:
	@echo $($(subst log-,,$@)) 





