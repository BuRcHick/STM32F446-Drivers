#ifndef _CONSOLE_API_H_
#define _CONSOLE_API_H_
#include <stdint.h>
#include "common_status.h"

cmn_status_t console_print_ln(uint8_t* fmt, ...);

cmn_status_t console_print_symbol(uint8_t chr);

cmn_status_t console_read_msg(uint8_t* data, uint16_t size);

#endif  //_CONSOLE_API_H_