#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template <class T>
vector<T> operator==(const vector<T>& v1, const vector<T>& v2) {
    return inner_product(begin(v1), end(v1), begin(v2), [&](auto a, auto b) { return a && b; },
                         [&](auto a, auto b) { return a == b; });
}

template <class T>
vector<T> operator==(const vector<vector<T>>& v1, const vector<vector<T>>& v2) {
    return inner_product(begin(v1), end(v1), begin(v2), [&](auto a, auto b) { return a && b; },
                         [&](auto a, auto b) { return a == b; });
}
