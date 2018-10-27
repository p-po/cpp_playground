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
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    std::cout << "Sum of 1 ... " << n << " is: " << sum << std::endl;
}
