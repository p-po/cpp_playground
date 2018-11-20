#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

using namespace std;

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

    vector<int> list1(n);
    for (size_t i = 0; i < n; ++i) {
        list1[i] = uniform_dist(e1);
    }
    sort(list1.begin(), list1.end(), [](auto &a, auto &b) -> bool {return a < b;});

    cout << "List 1 contains: ";
    for (size_t i = 0; i < n; ++i) {
        cout << list1[i] << " ";
    }
    cout << endl;

    vector<int> list2(n);
    for (size_t i = 0; i < n; ++i) {
        list2[i] = uniform_dist(e1);
    }
    sort(list2.begin(), list2.end(), [](auto &a, auto &b) -> bool {return a < b;});

    cout << "List 2 contains: ";
    for (size_t i = 0; i < n; ++i) {
        cout << list2[i] << " ";
    }
    cout << endl;

    vector<int> merge_list;
    merge_list.reserve(list1.size() + list2.size());
    int i = 0, j = 0;

    while (i < list1.size() && j < list2.size()) {
        if (list1[i] < list2[j]) merge_list.push_back(list1[i++]);
        else merge_list.push_back(list2[j++]);
    }

    while (i < list1.size()) merge_list.push_back(list1[i++]);
    while (j < list2.size()) merge_list.push_back(list2[j++]);

    cout << "Merged list contains: ";
    for (size_t i = 0; i < merge_list.size(); ++i) {
        cout << merge_list[i] << " ";
    }
    cout << endl;
}
