#include <iostream>
#include <math.h>

int main()
{
    static const int fract = 8;
    float i = 15.00205;
    int raw = 0;
    float result = 0;


    raw = roundf(i * (1 << fract));
    std::cout << raw << std::endl;

    result = (float)raw / (1 << fract);
    std::cout << result << std::endl;

    return (0);
}
