This is a plain C setup for how to use different implementations of the same API in a project, with the possibility of switching implementations at runtime and adding or removing implementations without the need to rebuild your entire project.

The current code is just a simple example - in this case, of printing the same message in different ways. You can easily build your own by replacing the `lib/print-{lowercase,uppercase,widecase}.c` files by different implementations of your own API,
and replacing the example functions in `lib/functions.h` with your own. You can then `#include` the header file `lib/print-generic.h` in your own program and link to `lib\libprint-generic.so`. 
If you want to build your project with a fixed implementation, you can `#include "lib/print.h"` and link to that specific implementation.

Of course, you can also replace `print` with a more fitting name.
