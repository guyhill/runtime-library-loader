#include "functions.h"

#define X(type, name, args, errorval) extern type (*name)args;
LIST_FUNCTIONS
#undef X

extern void loadlib(const char *name);
