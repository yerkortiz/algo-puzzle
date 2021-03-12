#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
int main(void) {
    long long n, i, median, median2, cnt, cnt2; std::cin >> n;
    std::vector<int> v(n);
    for(i = 0; std::cin >> v[i]; ++i)
        ;
    std::sort(v.begin(), v.end());
    median = v[n >> 1];
    median2 = v[(n >> 1) - 1];
    for(i = 0, cnt = 0, cnt2 = 0; i < n; ++i) {
        cnt += abs(median - v[i]);
        cnt2 += abs(median2 - v[i]);
    }
    std::cout<<std::min(cnt, cnt2)<<'\n';
    return 0;
}