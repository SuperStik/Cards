#ifndef _STIK_MACROS
#define _STIK_MACROS 1

#include <stdio.h>
#define PRINTINT(intz) printf("%i\n", intz)
#define SQR(sqrt) sqrt * sqrt
#define CUB(cbrt) cbrt * cbrt * cbrt
#define PUTSN(str) fputs(str, stdout)
#define GETSN(str, max) fgets(str, max, stdin)
#define errs(str) fputs(str "\n", stderr)

#endif
