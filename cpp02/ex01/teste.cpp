#include <iostream>
#include <math.h>

int main()
{
    static const int fract = 8;
    int i = 15;
    int i2 = 5;
    int raw = 0;
    int raw2 = 0;
    int raw_result = 0;
    int result = 0;


    raw = i << fract;
    std::cout << "raw1: " << raw << std::endl;

    raw2 = i2 << fract;
    std::cout << "raw2: " << raw2 << std::endl;

    raw_result = raw + raw2;
    result = raw_result >> fract;
    std::cout << "raw result: " << raw_result << " result: " << result << std::endl;
    return (0);
}
