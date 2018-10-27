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

    std::cout << "Enter 1 to calculate 1 + 2 + ... + n or anything else to calculate 1 * 2 * .... * n" << std::endl;
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (choice == 1) {
        for (size_t i = 1; i <= n; ++i)
            sum += i;
        std::cout << "1 + 2 + ... + n = " << sum << std::endl;
    } else {
        sum = 1;
        for (size_t i = 1; i <= n; ++i)
            sum *= i;
        std::cout << "1 * 2 * ... * n = "<< sum << std::endl;
    }
}
