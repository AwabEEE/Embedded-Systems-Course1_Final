#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST
	LDFLAGS =
	INCLUDES = -Iinclude/common
	SOURCES = src/main.c src/memory.c src/data.c src/course1.c

else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 \
	         -mcpu=cortex-m4 -mthumb -march=armv7e-m \
	         -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
	CPPFLAGS = -DMSP432
	LDFLAGS = -T msp432p401r.lds
	INCLUDES = -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS
	SOURCES = src/main.c src/memory.c src/data.c src/course1.c \
	          src/startup_msp432p401r_gcc.c src/system_msp432p401r.c \
	          src/interrupts_msp432p401r_gcc.c
endif

.PHONY: build

build: c1m2.out

c1m2.out: $(SOURCES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $^

	@echo "Build completed for $(PLATFORM)"

.PHONY: compile-all

ifeq ($(PLATFORM),HOST)
compile-all:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/main.c -o main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/memory.c -o memory.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/data.c -o data.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/course1.c -o course1.o

else ifeq ($(PLATFORM),MSP432)
compile-all:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/main.c -o main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/memory.c -o memory.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/data.c -o data.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/course1.c -o course1.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/system_msp432p401r.c -o system_msp432p401r.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c src/interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.o
endif

.PHONY: clean

clean:
	rm -f *.o *.out *.map *.i *.asm
	@echo "Clean completed"

