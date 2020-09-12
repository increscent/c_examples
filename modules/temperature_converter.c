#include "temperature_converter.h"

double fahr_to_celcius(double fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

double celcius_to_fahr(double celcius)
{
    return ((9.0 / 5.0) * celcius) + 32.0;
}

double convert_temp(double temp, int type)
{
    switch (type)
    {
        case FAHR_TO_CELCIUS:
            return fahr_to_celcius(temp);
        case CELCIUS_TO_FAHR:
            return celcius_to_fahr(temp);
        default:
            return temp;
    }
}
