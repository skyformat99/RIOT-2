/*
 * Copyright (C) 2017	Ken Rabold
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_hifive HiFive1
 * @{
 *
 * @file
 * @brief       Support for the HiFive1 RISC-V board
 *
 * @author      Ken Rabold
 *
 * @}
 */

#include <stdio.h>
#include <errno.h>

#include "cpu.h"
#include "board.h"
#include "periph/gpio.h"
#include "sifive/encoding.h"
#include "sifive/platform.h"
#include "sifive/prci_driver.h"

void board_init(void) {
	//	Init CPU
	cpu_init();

	//	Configure clocks
	//PRCI_use_default_clocks();
	PRCI_use_bypass_clock();

	//	Configure pin muxing for UART0
	GPIO_REG(GPIO_OUTPUT_VAL) |= IOF0_UART0_MASK;
	GPIO_REG(GPIO_OUTPUT_EN) |= IOF0_UART0_MASK;
	GPIO_REG(GPIO_IOF_SEL) &= ~IOF0_UART0_MASK;
	GPIO_REG(GPIO_IOF_EN) |= IOF0_UART0_MASK;

	//	Configure GPIOs for LEDs
	gpio_init(LED0_PIN, GPIO_OUT);
	gpio_init(LED1_PIN, GPIO_OUT);
	gpio_init(LED2_PIN, GPIO_OUT);

	//	Turn all the LEDs off
	LED0_OFF;
	LED1_OFF;
	LED2_OFF;

	//	Initialize newlib-nano stubs
	nanostubs_init();
}
