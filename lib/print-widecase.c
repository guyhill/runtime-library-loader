#include <stdio.h>

void print(const char *msg) {
		
	for (size_t i = 0; msg[i]; i++) {
		putchar(msg[i]);
		putchar(' ');
	}
}

void println(const char *msg) {
		
	print(msg);
	putchar('\n');
}
