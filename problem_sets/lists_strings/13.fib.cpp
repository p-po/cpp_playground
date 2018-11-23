#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void get_string(unsigned __int128 t, char *s)
{
    size_t pos = 0;
    while (t) {
        s[pos++] = '0' + t % 10;
        t = t / 10;
    }
}

std::ostream& operator<<(std::ostream& os, unsigned __int128 t) {
    char s[128] = {0};
    get_string(t, s);
    reverse(s, s + strlen(s));
    return os << s;
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
