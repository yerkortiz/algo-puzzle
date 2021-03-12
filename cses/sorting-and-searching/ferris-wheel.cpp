#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vctr_t;
int main(){
    int n, x, i, j, c = 0; std::cin >> n >> x;
    vctr_t child_weight(n);
    for(i = 0; i < n and std::cin >> child_weight[i]; ++i)
        ;
    sort(child_weight.begin(), child_weight.end());
    for(i = 0, j = n - 1; j > i; --j) {
        if(child_weight[i] + child_weight[j] <= x) {
            ++c, ++i;
            continue;
        }
    }
    c += (n - (c << 1));
    std::cout<<c<<'\n';
    return 0;
}