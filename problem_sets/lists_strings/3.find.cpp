#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

int main(void)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);

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

    std::cout << "List contains: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl << "Enter a number to check whether it's in the list: ";
    int elem;
    std::cin >> elem;

    bool found = std::find(list.begin(), list.end(), elem) != list.end();

    std::cout << "'" << elem << "'" << (found ? "" : " not") << " found in the list." << std::endl;
}
