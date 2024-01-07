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
LL qzh[maxn][maxn];
LL hzh[maxn][maxn];
LL f[maxn][maxn];
LL zf[maxn][maxn];
LL yf[maxn][maxn];
LL syou[maxn][maxn];
LL szuo[maxn][maxn];

inline void solve() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(aa[i][j]);
			qzh[i][j] = qzh[i][j - 1] + aa[i][j];
		}
		hzh[i][m + 1] = 0;
		for (int j = m; j; --j) {
			hzh[i][j] = hzh[i][j + 1] + aa[i][j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		f[n][i] = aa[n][i];
	}
	for (int i = n - 1; i; --i) {
		zf[i][1] = f[i + 1][1] + aa[i][1];
		for (int j = 2; j <= m; ++j) {
			zf[i][j] = max(zf[i][j - 1], f[i + 1][j]) + aa[i][j];
		}
		yf[i][m] = f[i + 1][m] + aa[i][m];
		for (int j = m - 1; j; --j) {
			yf[i][j] = max(yf[i][j + 1], f[i + 1][j]) + aa[i][j];
		}
		syou[i][m] = szuo[i][1] = inf;
		for (int j = m - 1; j; --j) {
			syou[i][j] = (qzh[i][j] << 1) - aa[i][1] + qzh[i][j] + yf[i][j + 1] - aa[i][j];
			syou[i][j] = min(syou[i][j + 1], syou[i][j]);
//			if (i == 1) {
//				cout << j << ' ' << yf[i][j + 1] << endl;
//			}
		}
		for (int j = 2; j <= m; ++j) {
			szuo[i][j] = (hzh[i][j] << 1) - aa[i][m] + hzh[i][j] + zf[i][j - 1] - aa[i][j];
			szuo[i][j] = min(szuo[i][j - 1], szuo[i][j]);
		}
		f[i][1] = yf[i][1], f[i][m] = zf[i][m];
		for (int j = 2; j < m; ++j) {
			LL zuo = max(zf[i][j - 1] + aa[i][j], yf[i][j + 1] + (qzh[i][j] << 1) - aa[i][1]);
			LL you = max(yf[i][j + 1] + aa[i][j], zf[i][j - 1] + (hzh[i][j] << 1) - aa[i][m]);
			LL zz = max(max(zf[i][j], yf[i][j] + aa[i][j] + aa[i][j - 1]), szuo[i][j - 1] - hzh[i][j + 1]);
			LL yy = max(max(zf[i][j] + aa[i][j] + aa[i][j + 1], yf[i][j]), syou[i][j + 1] - qzh[i][j - 1]);
			f[i][j] = max(aa[i][j] + f[i + 1][j], min(min(zz, zuo), min(yy, you)));
		}
	}
	LL ans = inf;
	for (int i = 1; i <= m; ++i) {
		ans = min(ans, f[1][i]);
	}
	writeln(ans);
}

int main() {
	solve();
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
