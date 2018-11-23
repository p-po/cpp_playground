#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> get_digits(size_t num)
{
    vector<int> res;
    res.reserve(128);

    while(num) {
        res.push_back(num % 10);
        num = num / 10;
   }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    size_t n;
    std::cout << "Enter list size (auto generated): ";
    std::cin >> n;

    vector<int> digits = get_digits(n);

    for (auto it = digits.begin(); it != digits.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
