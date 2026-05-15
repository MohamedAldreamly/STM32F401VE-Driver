TARGET = firmware
BUILD_DIR = build

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

RM = rm -rf
MKDIR = mkdir -p

MCU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
DEFS = -DSTM32F401xE

INCLUDES = \
-I Drivers/CMSIS/Include \
-I Drivers/CMSIS/Device/ST/STM32F4xx/Include \
-I LIB \
-I MCAL \
-I HAL \
-I MCAL/RCC \
-I MCAL/GPIO \
-I MCAL/NVIC \
-I MCAL/SYSTICK \
-I MCAL/STK \
-I MCAL/EXTI \
-I MCAL/USART \
-I HAL/SW \
-I HAL/LED \
-I HAL/SSD \
-I HAL/KPD

CFLAGS = $(MCU) $(DEFS) $(INCLUDES) \
-Wall -O0 -g \
-ffunction-sections -fdata-sections

LDSCRIPT = STM32F401VETX_FLASH.ld

SOURCES = \
main.c \
Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c \
$(wildcard MCAL/*/*.c) \
$(wildcard HAL/*/*.c) \
$(wildcard LIB/*/*.c)

ASM_SOURCES = \
startup_stm32f401xe.s

OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SOURCES))
OBJECTS += $(patsubst %.s,$(BUILD_DIR)/%.o,$(ASM_SOURCES))

LDFLAGS = $(MCU) \
-T$(LDSCRIPT) \
-Wl,--gc-sections \
-Wl,-Map=$(BUILD_DIR)/$(TARGET).map

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(BUILD_DIR)/%.o: %.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.s
	$(MKDIR) $(dir $@)
	$(CC) $(MCU) -c $< -o $@

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

firmware.hex: $(BUILD_DIR)/$(TARGET).hex

clean:
	$(RM) $(BUILD_DIR)