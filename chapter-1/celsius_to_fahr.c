#include <stdio.h>

#define LOWER_CELSIUS 0
#define HIGHER_CELSIUS 300
#define TEMPERATURE_STEP 20

int main()
{
    for (int celsius = HIGHER_CELSIUS; celsius >= LOWER_CELSIUS; celsius -= TEMPERATURE_STEP)
    {
        printf("%3d %6.1f\n", celsius, (9.0 / 5.0) * celsius + 32.0);
    }
}