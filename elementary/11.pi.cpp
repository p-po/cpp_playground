#include <iostream>
#include <cmath>
#include <iomanip>

int main(void)
{
    double sum = 0;

    for (size_t k = 1; k <= 1000000; ++k) {
        int sign = k % 2 ? 1 : -1;
        sum += (1/(2.0 * k - 1)) * sign;
    }

    std::cout << std::setprecision(16) << "PI: " << 4 * sum << "\nM_PI: " << M_PI << std::endl;
}
