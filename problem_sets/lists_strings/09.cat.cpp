#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

std::vector<int> concat_list(std::vector<int>& l1, std::vector<int>& l2)
{
    std::vector<int> new_list;
    new_list.reserve(l1.size() + l2.size());

    new_list.insert(new_list.end(), l1.begin(), l1.end());
    new_list.insert(new_list.end(), l2.begin(), l2.end());

    return new_list;
}

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

    std::vector<int> list1(n);
    for (size_t i = 0; i < n; ++i) {
        list1[i] = uniform_dist(e1);
    }

    std::cout << "List 1 contains: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << list1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> list2(n);
    for (size_t i = 0; i < n; ++i) {
        list2[i] = uniform_dist(e1);
    }

    std::cout << "List 2 contains: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << list2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> new_list = concat_list(list1, list2);

    std::cout << "Concatenated list contains: ";
    for (size_t i = 0; i < new_list.size(); ++i) {
        std::cout << new_list[i] << " ";
    }
    std::cout << std::endl;
}
