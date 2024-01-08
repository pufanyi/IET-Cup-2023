#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    while (n) {
        if (n % 10 == 6) {
            ++ans;
        }
        n /= 10;
    }
    std::cout << ans << '\n';
    return 0;
}