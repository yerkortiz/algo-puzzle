#include <iostream>
#include <vector>
typedef std::vector<long long> vctr_t;
const long long min_num = -(long long) (1 << 30);
int main(void) {
    long long n, i, j, sum, max = 0; std::cin >> n; vctr_t v(n);
    for(i = 0; i < n; ++i)
        std::cin >> v[i];
    for(j = 0, sum = 0; j < n; ++j) {
        sum += v[j];
        if(sum < 0)
            sum = 0;
        if(sum > max)
            max = sum;
    }
    long long max_2 = min_num;
    for(i = 0; i < n; ++i)
        if(v[i]> max_2)
            max_2 = v[i];
    if(max > max_2 and max)
        std::cout<<max<<'\n';
    else
        std::cout<<max_2<<'\n';
    return 0;
}