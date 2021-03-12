#include <iostream>
#include <set>
#include <vector>
 
int main() {
    int n, m, x;
    std::cin >> n >> m;
    std::multiset<int, std::greater<int>> tree;
    while (n--) {
        std::cin >> x;
        tree.insert(x);
    }
    while (m--) {
        std::cin >> x;
        auto it = tree.lower_bound(x);
        if (it == tree.end()) {
            std::cout << "-1\n";
        } else {
            std::cout << *it << '\n';
            tree.erase(it);
        }
    }
}