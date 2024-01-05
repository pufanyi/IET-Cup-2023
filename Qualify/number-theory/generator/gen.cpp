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
    std::cout << st.size() << ' ' << k << '\n';
    std::vector<int> ve(st.begin(), st.end());
    shuffle(ve.begin(), ve.end());
    for (decltype(st.size()) i = 0; i < st.size(); ++i) {
        if (i != 0) {
            std::cout << ' ';
        }
        std::cout << ve[i];
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

void gen_random(int n, int k) {
    std::set<int> st;
    while ((int) st.size() < n) {
        st.insert(rnd.next(1, MAX_X));
    }
    output(k, st);
}

void gen(int n, int min_k, int max_k, int non_random_part, int opt) {
    int k = rnd.next(min_k, max_k);
    if (opt == 0) {
        gen_can(n, k, non_random_part);
    } else if (opt == 1) {
        gen_cant(n, k, non_random_part);
    } else if (opt == 2) {
        gen_random(n, k);
    } else {
        assert(false);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    int T = std::atoi(argv[2]);
    int n = std::atoi(argv[3]);
    int min_k = std::atoi(argv[4]);
    int max_k = std::atoi(argv[5]);
    int non_random_part = n * std::atoi(argv[6]) / 100;
    int opt = std::atoi(argv[7]);
    std::cout << T << '\n';
    while (T--) {
        gen(n, min_k, max_k, non_random_part, opt);
    }
    return 0;
}
