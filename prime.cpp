#include <iostream>
#include <limits>
#include <cmath>

int main(void)
{
    intmax_t n;
    std::cout << "Please input a number (all primes upto which will be printed):" << std::endl;

    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (intmax_t i = 2; i <= n; ++i) {
        intmax_t j = 2;
        intmax_t root = std::sqrt(i);
        for (; j <= root; ++j)
            if (i % j == 0) break;

        if (j == root + 1) std::cout << i << " ";
    }

    std::cout << std::endl;
}
