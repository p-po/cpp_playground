#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

std::vector<int> odd_pos_list(std::vector<int>& list)
{
    size_t size = list.size();
    std::vector<int> odd(size / 2 + size % 2);
    bool flag = true;

    for (auto it = list.begin(), oit = odd.begin(); it != list.end(); ++it) {
        if (flag) *oit++ = *it;
        flag = !flag;
    }

    return odd;
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

    std::vector<int> odd_list = odd_pos_list(list);

    for (auto it = odd_list.begin(); it != odd_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}
