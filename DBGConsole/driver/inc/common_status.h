#ifndef _COMMON_STATUS_H_
#define _COMMON_STATUS_H_

typedef enum {
	OK,
	ERR,
	INV_ARG,
	TIMEOUT
}cmn_status_t;

const char* cmn_status_to_string(const cmn_status_t status);

#endif //_COMMON_STATUS_H_