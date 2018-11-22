#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, unsigned __int128 t) {
    string st("hi");
    return os << str;
}

template<unsigned __int128 n> struct fib
{
    static constexpr unsigned __int128 value = fib<n-1>::value + fib<n-2>::value;

    static void gen_arr(vector<unsigned __int128> &arr) {
        fib<n-1>::gen_arr(arr);
         arr.push_back(value);
    }

};

template<> struct fib<0>
{
    static constexpr unsigned __int128 value  = 0;

    static void gen_arr(vector<unsigned __int128> &arr) {
        arr.push_back(value);
    }
};

template<> struct fib<1>
{
    static constexpr unsigned __int128 value = 1;

    static void gen_arr(vector<unsigned __int128> &arr) {
        fib<0>::gen_arr(arr);
        arr.push_back(value);
    }
};

int main()
{
    vector<unsigned __int128> arr;
    fib<100>::gen_arr(arr);

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
