#include <stdio.h>
#include <ctype.h>

void print(const char *msg) {
		
	for (size_t i = 0; msg[i]; i++) {
		putchar(toupper(msg[i]));
	}
}

void println(const char *msg) {
		
	print(msg);
	putchar('\n');
}
