#ifndef _SHA_1_H_
#define _SHA_1_H_

#include <cstring>
#include "uInt160.h"
struct Message {
	char * buf;
	int len;
	Message(char * buf, int len = -1) {
		this->buf = buf;
		if (len != -1)
			this->len = len;
		else
			this->len = strlen(buf);
	}
};










#endif

