#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    const std::string t = "ietntu";
    std::string s;
    std::cin >> s;
    std::string::const_iterator it = t.begin();
    for (const char c: s) {
        if (c == *it) {
            ++it;
        }
    }
    if (it == t.end()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}