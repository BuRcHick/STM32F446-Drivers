#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include "console_api.h"
#include "stm32f4xx_hal.h"
#define CNSL_CHECK_ERR(c, e) \
	{                        \
		if (!(c)) {          \
			return e;        \
		}                    \
	}

#define CONSOLE_MSG_SIZE 0x100
#define CONSOLE_TIMEOUT 10000

extern UART_HandleTypeDef huart2;
static uint8_t s_console_msg[CONSOLE_MSG_SIZE] = {0};

cmn_status_t console_print_ln(uint8_t* fmt, ...) {
	assert(fmt);
	va_list valist;
	va_start(valist, fmt);
	memset(s_console_msg, 0, CONSOLE_MSG_SIZE);
	sprintf((char*)s_console_msg, "\n\r");
	vsprintf((char*)s_console_msg + strlen((char*)s_console_msg), (char*)fmt, valist);
	sprintf((char*)s_console_msg + strlen((char*)s_console_msg), "\n\r");
	va_end(valist);
	CNSL_CHECK_ERR(HAL_UART_Transmit(&huart2, s_console_msg, strlen((char*)s_console_msg), CONSOLE_TIMEOUT) == HAL_OK, ERR);
	return OK;
}

cmn_status_t console_print_symbol(uint8_t chr)
{
	memset(s_console_msg, 0, CONSOLE_MSG_SIZE);
	sprintf((char*)s_console_msg, "%c",(char)chr);
	CNSL_CHECK_ERR(HAL_UART_Transmit(&huart2, s_console_msg, strlen((char*)s_console_msg), CONSOLE_TIMEOUT) == HAL_OK, ERR);
	return OK;
}

cmn_status_t console_read_msg(uint8_t* data, uint16_t size) {
	assert(data);
	CNSL_CHECK_ERR(size > 0, INV_ARG);
	CNSL_CHECK_ERR(HAL_UART_Receive(&huart2, data, size, CONSOLE_TIMEOUT) == HAL_OK, ERR);
	return OK;
}