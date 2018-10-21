#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <functional>

int psquare(int x)
{
    // Needs overflow check
    return x * x;
}

std::vector<int> on_all(const std::vector<int>& list, std::function<int(int)> func)
{
    std::vector<int> sq(list.size());
    auto sit = sq.begin();
    for (auto it = list.begin(); it != list.end(); ++it)
        *sit++ = func(*it);

    return sq;
}

int main(void)
{
    size_t n = 20;

    std::vector<int> list(n);
    std::iota(list.begin(), list.end(), 1);

    std::cout << "List contains: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> new_list = on_all(list, &psquare);

    std::cout << "Perfect squares [1, 20]:";
    for (auto it = new_list.begin(); it != new_list.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}
