#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long long_t;
long_t sum = 0, subset_sum = 0, ans = 0;
std::vector<long_t> subset, v;
void solution(int w, int k) {
    if(w == k) {
        ans = std::min(llabs(sum - 2*subset_sum), ans);
        return;
    }else {
        subset_sum += v[w];
        subset.push_back(v[w]);
        solution(w + 1, k);
        subset_sum -= subset.back();
        subset.pop_back();
        solution(w + 1, k);
    }
}
int main() {
    long_t k; std::cin >> k;
    v.resize(k);
    for(long_t i = 0; i < k; ++i){
        std::cin>>v[i];
        sum += v[i];
    }
    ans = sum;
    solution(0, k);
    std::cout<<ans<<'\n';
    return 0;
}