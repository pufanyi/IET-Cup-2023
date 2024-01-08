#include <string>
#include <iostream>

void solve() {
    std::string s;
    std::string t = "ietntu";
    std::cin >> s;
    int now = 0;
    for (char c: s) {
        if (c == t[now]) {
            ++now;
        }
    }
    std::cout << (now == 6 ? "Yes" : "No") << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}