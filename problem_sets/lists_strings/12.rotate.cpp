#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>

using namespace std;

template <typename T>
void rotate_by_N(vector<T>& v, size_t N)
{
    auto it = v.begin();
    std::rotate(it, it + N, v.end());
}

int main(void)
{
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(1, 1000 /*numeric_limits<int>::max() */);

    size_t n;
    cout << "Enter list size (auto generated): ";
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> list(n);
    for (size_t i = 0; i < n; ++i) {
        list[i] = uniform_dist(e1);
    }

    cout << "List contains: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    int N;
    cout << "Input N (rotate len): ";
    cin >> N;
    rotate_by_N(list, N);

    cout << "List contains (after rotation): ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
