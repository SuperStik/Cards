#include "utils.h"
#include <stdlib.h>
#include <time.h>
void scansafe(void* scanfor, const char* seq, const char* msg, const char* err) {
	fputs(msg, stdout);
	long pos = ftell(stdin);
	while (scanf(seq, scanfor) < 1 || ferror(stdin) != 0) {
		puts(err);
		if (fseek(stdin, pos, SEEK_SET) != 0) {
			fputs("Failed to rewind stdin!\n", stderr);
			exit(EXIT_FAILURE);
		}
		clearerr(stdin);
		fputs(msg, stdout);
	}
}

int randomrange(int start, int stop) {
	return start + rand() / (RAND_MAX / (stop - start));
}
