#include "common_status.h"
#include <stdlib.h>
const char* cmn_status_to_string(const cmn_status_t status) {
	switch (status) {
		case OK:
			return "OK";
		case ERR:
			return "ERR";
		case INV_ARG:
			return "INV_ARG";
		case TIMEOUT:
			return "TIMEOUT";
		default:
			return NULL;
	}
}