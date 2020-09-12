#include <stdio.h>

#include "temperature_converter.h"

int main()
{
    double celcius = convert_temp(40.0, FAHR_TO_CELCIUS);
    printf("40.0 degrees fahrenheit is %6.1f degrees celcius\n", celcius);
}
