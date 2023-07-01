#include <iostream>
#include <math.h>

int main()
{
    static const int fract = 8;
    float i1 = 1345.02501;
    float i2 = 1345.02501;
    int raw1 = 0;
    int raw2 = 0;
    float result1 = 0;
    float result2 = 0;

    raw1 = roundf(i1 * (1 << fract));
    std::cout << "raw1: " << raw1 << " pow: " << (1 << fract) << std::endl;

    result1 = (float)raw1 / (float)(1 << fract);
    std::cout << "result1: " << result1 << std::endl;


    int power = pow(2, fract);
    raw2 = roundf(i2 * power);
    std::cout << "raw2: " << raw2 << " pow: " << power << std::endl;

    result2 = (float)raw2 / power;
    std::cout << "result2: " << result2 << std::endl;
    return (0);
}
