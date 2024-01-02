#include <atomic>
#include <array>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "testlib.h"

using LL = long long;

constexpr int maxn = 5000005;

void mkdata(int n, int k, int q, int m, int div) {
	// memset(xx, 0, sizeof(xx));
    std::array<int, maxn> xx;
	std::cout << n << ' ' << k << ' ' << q << '\n';
	int lim = n / div;
	int __T = 0;
	for (int i = lim + 1; i <= n; ++i) {
		// int pla = rnd() % m + 1;
        int pla = rnd.next(1, m);
		while (xx[pla]) {
            pla = rnd.next(1, m);
			// pla = rnd() % m + 1;
		}
		// int hh = rnd() % (k / 2) + 1;
        int hh = rnd.next(1, k / 2);
		xx[pla] = hh;
		__T++;
	}
	for (int i = 1; i <= lim; ++i) {
		// int pla = rnd() % m + 1;
        int pla = rnd.next(1, m);
		while (xx[pla]) {
			// pla = rnd() % m + 1;
            pla = rnd.next(1, m);
		}
        int hh = rnd.next(k / 2 + 1, k);
		// int hh = k - rnd() % (k / 2);
		xx[pla] = hh;
		__T++;
	}
	assert(__T == n);
	std::vector<std::pair<int, int>> ve;
	int mm = m;
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (xx[i]) {
			ve.emplace_back(i, xx[i]);
			cnt++;
			mm = std::max(m, i + k);
		}
	}
	assert(cnt == n);
	shuffle(ve.begin(), ve.end());
	for (auto x : ve) {
		std::cout << x.first << ' ' << x.second << '\n';
	}
	for (int i = 1; i <= q; ++i) {
        int l = rnd.next(1, mm);
        int r = rnd.next(l, mm);
		if (l > r) {
			std::swap(l, r);
		}
		std::cout << l << ' ' << r << '\n';
	}
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int seed = std::atoi(argv[1]);
    rnd.setSeed(seed);
    int n = std::atoi(argv[2]);
    int k = std::atoi(argv[3]);
    int q = std::atoi(argv[4]);
    int m = std::atoi(argv[5]);
    int div = std::atoi(argv[6]);
    mkdata(n, k, q, m, div);
    return 0;
}