#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <iterator>

int main(void)
{
    std::string str;
    std::cin >> str;

    auto s = str.begin(), e = str.end() - 1;
    for(;s < e && *s == *e; ++s, --e);

    std::cout << (s >= e ? "Palindrome" : "Not a palindrom") << std::endl;
}
