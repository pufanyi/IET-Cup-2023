#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (char c: s) {
        if (c == '6') {
            ++ans;
        }
    }
    std::cout << ans << '\n';
    return 0;
}