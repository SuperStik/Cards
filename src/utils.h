#ifndef _STIK_UTILS
#define _STIK_UTILS 1

#include "macros.h"

// Will loop endlessly until a valid sequence is detected
#ifdef __cplusplus
extern "C" {
#endif
void scansafe(void*, const char *format, const char *msg, const char *err);

// Generate a random number between two integers
int randomrange(int start, int stop);
#ifdef __cplusplus
}
#endif
#endif
