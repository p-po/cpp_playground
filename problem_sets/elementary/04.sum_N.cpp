#include <iostream>
#include <limits>

int main(void)
{
    size_t n, sum = 0;
    std::cout << "Please input a number:" << std::endl;

    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (size_t i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "Sum of 1 ... " << n << " is: " << sum << std::endl;
    std::cout << "Sum of 1 ... " << n << " is (without loop): " << (n * (n + 1) / 2) << std::endl;
}
