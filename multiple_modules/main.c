#include <stdio.h>

#include "module_interface.h"

/*
 * The main module is the same no matter which other module is linked in
 */
int main()
{
    module_function(1, 2);

    return 0;
}
