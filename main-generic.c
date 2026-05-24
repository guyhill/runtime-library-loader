#include <stdlib.h>
#include <stdio.h>

#include "print-generic.h"

int main(void) {
	char *libs[] = {
		"lib/libprint-upper.so", 
		"lib/libprint-lower.so", 
		"lib/libprint-wide.so"
	};
	char *msg = "TeStCaSe\n";
	
	int i, option, none_value, exit_value;
	
	print(msg);
	printf("\n");
	
	while(1) {
		for (i=0; i<sizeof libs / sizeof *libs; i++) {
			printf("%i - %s\n", i, libs[i]);
		}
		printf("%i - none\n", i);
		none_value = i++;
		printf("%i - exit\n", i);
		exit_value = i;
		
		printf("\nChoose library to load: ");
		scanf("%d", &option);
		 
		if (option == exit_value) {
			break;
		} else if (option == none_value) {
			loadlib(NULL);
		} else {
			loadlib(libs[option]);
		}
		
		print(msg);		
		printf("\n");
	}
	return EXIT_SUCCESS;
}
