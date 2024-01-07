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

#ifndef _AT_HOME
#define dd c = gc()
#else
#define dd c = getchar()
#endif
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

template <class T>
inline void writesp(T x) {
	write(x);
	putchar(' ');
}

template <class T>
inline void writeln(T x) {
	write(x);
	puts("");
}

typedef long long LL;

const LL inf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 505;

int n, m;
int aa[maxn][maxn];
LL f[maxn][maxn][maxn][2];
LL qzh[maxn][maxn];

inline LL dp(int x, int l, int r, int opt) {
	if (l < 1 || r > m) {
		return inf;
	}
	if (x == n) {
		return 0;
	}
	if (~f[x][l][r][opt]) {
		return f[x][l][r][opt];
	}
	if (l == 1 && r == m) {
		return f[x][l][r][opt] = opt ? dp(x + 1, r, r, opt) + aa[x + 1][r] : dp(x + 1, l, l, opt) + aa[x + 1][l];
	}
	if (!opt) {
		return f[x][l][r][opt] = max(dp(x + 1, l, l, opt) + aa[x + 1][l],
		                             min(dp(x, l - 1, r, opt) + aa[x][l - 1],
		                                 dp(x, l, r + 1, opt ^ 1) + qzh[x][r] - qzh[x][l] + aa[x][r + 1]));
	} else {
		return f[x][l][r][opt] = max(dp(x + 1, r, r, opt) + aa[x + 1][r],
		                             min(dp(x, l - 1, r, opt ^ 1) + qzh[x][r - 1] - qzh[x][l - 1] + aa[x][l - 1],
		                                 dp(x, l, r + 1, opt) + aa[x][r + 1]));
	}
}

int main() {
	memset(f, 0xff, sizeof(f));
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(aa[i][j]);
			qzh[i][j] = qzh[i][j - 1] + aa[i][j];
		}
	}
	LL ans = inf;
	for (int i = 1; i <= m; ++i) {
		ans = min(ans, dp(1, i, i, 0) + aa[1][i]);
	}
	writeln(ans);
	return 0;
}

/*
1
3 4
0 1 1 2
3 3 3 2
3 0 0 0
*/

/*
1
3 4
0 1 0 1
2 0 2 0
1 2 3 0
*/

/*
1
3 4
0 1 0 2
0 2 3 1
1 3 0 2
*/

