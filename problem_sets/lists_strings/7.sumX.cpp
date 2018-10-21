#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

size_t for_sum(const std::vector<int>& list)
{
    size_t tot = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
        tot += *it;

    return tot;
}


size_t while_sum(const std::vector<int>& list)
{
    size_t tot = 0;
    auto it = list.begin();

    while (it != list.end()) {
        tot += *it++;
    }

    return tot;
}


size_t recur(const std::vector<int>& list, size_t pos)
{
    auto it = std::next(list.begin(), pos);

    if (it == list.end())
        return 0;

    return recur(list, pos + 1) + list[pos];
}

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
    std::cout << std::endl;

    std::cout << "Sum (for loop): " << for_sum(list) << std::endl;
    std::cout << "Sum (while loop): " << while_sum(list) << std::endl;
    std::cout << "Sum (recursion): " << recur(list, 0) << std::endl;
}
