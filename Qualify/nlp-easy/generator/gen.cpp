#include <iostream>
#include <algorithm>

#include "testlib.h"


const std::string DONT_HAVE = "abcdfghjklmopqrsvwxyz";
const std::string P = "ietntu";
const std::string HAVE_P = "ietnu";


char random_char(const std::string &s) {
    return s[rnd.next(0, static_cast<int>(s.size()) - 1)];
}


void gen_random(int n) {
    std::cout << rnd.next("[a-z]{" + std::to_string(n) + "}") << '\n';
}

std::string gen_core(int n) {
    // a string with char only "i", "e", "t", "n", "u"
    // dont have subsequence "ietntu"
    std::string s;
    auto now_p = P.begin();
    int prob = n / 5;
    for (int i = 1; i <= n; ++i) {
        if (now_p == P.end()) {
            s.push_back(random_char(HAVE_P));
        } else if (rnd.next(1, prob) == 1) {
            s.push_back(*now_p);
            now_p++;
        } else {
            char c;
            do {
                c = random_char(DONT_HAVE);
            } while (c == *now_p);
            s.push_back(c);
        }
    }
    return s;
}


void gen(int n, int core) {
    std::string s = gen_core(core);
    std::string t;
    for (int i = 0; i < n - core; ++i) {
        t.push_back(random_char(DONT_HAVE));
    }
    for (int i = 0; i < core; ++i) {
        t.push_back('#');
    }
    shuffle(t.begin(), t.end());
    auto now_c = s.begin();
    for (auto &c: t) {
        if (c == '#') {
            c = *now_c;
            now_c++;
        }
    }
    std::cout << t << '\n';
}


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    const int T = std::atoi(argv[2]);
    const int n = std::atoi(argv[3]);
    const int opt = std::atoi(argv[4]);
    int core = -1;
    if (opt == 1) {
        core = std::atoi(argv[5]);
    }
    std::cout << T << '\n';
    for (int i = 0; i < T; ++i) {
        if (opt == 0) {
            gen_random(n);
        } else if (opt == 1) {
            gen(n, core);
        } else {
            gen(n, rnd.next(6, n));
        }
    }
    return 0;
}
