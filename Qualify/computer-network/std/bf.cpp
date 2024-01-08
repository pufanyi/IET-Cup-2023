#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

inline char gc() {
	static const LL L = 233333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt) {
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) {
			return EOF;
		}
	}
	return *sss++;
}

#define dd c = gc()
inline char readalpha() {
	char dd;
	for (; !isalpha(c); dd);
	return c;
}

inline char readchar() {
	char dd;
	for (; c == ' '; dd);
	return c;
}

template <class T>
inline bool read(T& x) {
	bool flg = false;
	char dd;
	x = 0;
	for (; !isdigit(c); dd) {
		if (c == '-') {
			flg = true;
		} else if(c == EOF) {
			return false;
		}
	}
	for (; isdigit(c); dd) {
		x = (x << 1) + (x << 3) + (c ^ 48);
	}
	if (flg) {
		x = -x;
	}
	return true;
}
#undef dd

template <class T>
inline void write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x | 48);
		return;
	}
	write(x / 10);
	putchar((x % 10) | 48);
}

const int maxn = 1000005;

int n, k, q, lm;
int f[maxn << 2];
int hv[maxn << 2];
int hh[maxn << 2];

struct QJ {
	int l, r;

	friend bool operator < (const QJ& a, const QJ& b) {
		return a.l < b.l;
	}
} qj[maxn];

inline void query() {
	int l, r;
	read(l), read(r);
	r = min(r, lm << 1);
	if (l > r) {
		puts("Yes");
		return;
	}
	if (hh[l] || hh[r]) {
		puts("No");
		return;
	}
	for (int i = r; i <= r + k; ++i) {
		f[i] = 1;
	}
	for (int i = r - 1; i >= l; --i) {
		f[i] = 0;
		if (!hh[i]) {
			if (!hv[i + k]) {
				if (i == 3) {
					std::cerr << "111 " << l << ' ' << i + k << ' ' << hv[i + k] << std::endl;
				}
				f[i] |= f[i + k];
			}
			if (!hh[i + 1]) {
				f[i] |= f[i + 1];
			}
		}
	}
	for (int i = l; i <= r + k; ++i) {
		cout << hv[i] << ' ';
	}
	std::cout << std::endl;
	for (int i = l; i <= r + k; ++i) {
		cout << f[i] << ' ';
	}
	std::cout << std::endl;
	puts(f[l] ? "Yes" : "No");
}

int main() {
	// freopen("cactus.in", "r", stdin);
	// freopen("cactus.out", "w", stdout);
	read(n), read(k), read(q);
	// k++;
	for (int i = 1; i <= n; ++i) {
		read(qj[i].l), read(qj[i].r);
		qj[i].r += qj[i].l;
		lm = max(qj[i].r, lm);
		hh[qj[i].l] = 1;
	}
	sort(qj + 1, qj + n + 1);
	int now = 0, nx = 1;
	for (int i = 1; i <= lm; ++i) {
		if (nx <= n && i == qj[nx].l) {
			for (now = max(qj[nx].l, now); now <= qj[nx].r; ++now) {
				hv[now] = 1;
			}
			nx++;
		}
	}
	k <<= 1;
	std::cerr << "k = " << k << std::endl;
	cout << "hv = ";
	for (int i = 1; i <= lm; ++i) {
		cout << hv[i] << ' ';
	}
	cout << endl;
	while (q--) {
		query();
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
