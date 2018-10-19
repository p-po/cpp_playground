#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

int main(void)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, std::numeric_limits<int>::max());

    size_t n;
    std::cout << "Enter list size (auto generated): ";
    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> list(n);

    for (size_t i = 0; i < n; ++i) {
        list[i] = uniform_dist(e1);
    }

    std::cout << "Original list: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    std::reverse(list.begin(), list.end());

    std::cout << "Reversed list: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
