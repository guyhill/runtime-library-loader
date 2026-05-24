#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "functions.h"

#define X(type, name, args, errorval)                          \
    static type DUMMY_##name args {                            \
	    fprintf(stderr, "Function <" #name "> not loaded\n");  \
	    return errorval;                                       \
    }
LIST_FUNCTIONS
#undef X

#define X(type, name, args, errorval) \
    type (*name)args = DUMMY_##name;
LIST_FUNCTIONS
#undef X

// NOTE: current loadlib only works on systems that support the
// POSIX dlfcn.h (i.e., Linux, MacOS and other *NIX-es). 
// A different implementation is needed for MS Windows.
void loadlib(const char *name) {
	static void *lib = NULL;
	void *func;
	
	if (lib) {
		dlclose(lib);
		#define X(type, name, args, errorval) name = DUMMY_##name;
		LIST_FUNCTIONS
		#undef X		    
	}
	if (!name) return;
	
	lib = dlopen(name, RTLD_NOW | RTLD_LOCAL);
	if (!lib) {
		fprintf(stderr, "Failed to load %s: %s\n", name, dlerror());
		exit(EXIT_FAILURE);
	}
	#define X(type, name, args, errorval) \
	    func = dlsym(lib, #name);         \
	    if (func) name = func;
	LIST_FUNCTIONS
	#undef X
}
