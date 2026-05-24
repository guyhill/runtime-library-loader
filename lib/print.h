#include "functions.h"

#define X(type, name, args, errorval) type name args;
LIST_FUNCTIONS
#undef X
