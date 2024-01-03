#include <atomic>
#include <array>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

#include "testlib.h"

using LL = long long;

constexpr int MAX_X = (int) 1e9;
constexpr int MAX_N = (int) 1e5;

int get_div(int div) {
    return div * rnd.next(1, MAX_X / div);
}

std::set<int> get_set(int n, int div) {
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
        st.insert(get_div(div));
    }
    return st;
}

void output(int k, const std::set<int> &st) {
    std::cout << k << ' ' << st.size() << '\n';
    std::vector<int> ve(st.begin(), st.end());
    shuffle(ve.begin(), ve.end());
    for (int x : ve) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void gen_can(int n, int k, int non_random_part) {
    std::set<int> st = get_set(non_random_part, k);
    while ((int) st.size() < n) {
        st.insert(get_div(1));
    }
    output(k, st);
}

void gen_cant(int n, int k, int non_random_part) {
    std::set<int> st = get_set(non_random_part, get_div(k));
    while ((int) st.size() < n) {
        st.insert(rnd.next(1, MAX_X));
    }
    output(k, st);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    int n = std::atoi(argv[2]);
    int min_k = std::atoi(argv[3]);
    int max_k = std::atoi(argv[4]);
    int non_random_part = n * std::atoi(argv[5]) / 100;
    int opt = std::atoi(argv[6]);
    int k = rnd.next(min_k, max_k);
    if (opt == 0) {
        gen_can(n, k, non_random_part);
    } else if (opt == 1) {
        gen_cant(n, k, non_random_part);
    } else {
        assert(false);
    }
    return 0;
}