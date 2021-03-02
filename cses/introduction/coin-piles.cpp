#include <iostream>
#include <vector>
typedef unsigned long long long_t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long_t t; 
    std::cin >> t;
    long_t a, b;
    for(;cin >> a >> b;) {
        std::cout << (!((a + b) % 3) && min(a, b) * 2 >= max(a, b) ? "YES\n" : "NO\n");
    }
    return 0;
}