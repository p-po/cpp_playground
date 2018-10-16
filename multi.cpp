#include <iostream>
#include <limits>
#include <iomanip>

int main(void)
{
    size_t n, sum = 0;
    std::cout << "Please input a number:" << std::endl;

    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= 12; ++j) {
            std::cout << std::setw(4) << j << " * " << i << " = " << j * i << std::endl;
        }
        std::cout << std::endl << "===============" << std::endl;
    }
}
