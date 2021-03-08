#include <iostream>
#include <string>

void search(uint64_t k) {
    uint64_t sum = 0, sum2 = 0;
    for(uint64_t i = 1, j = 1; ; ++i, j *= 10){
        sum += i*9*j;
        sum2 += 9*j;
        if(sum >= k){
            k -= (sum - i*9*j);
            std::string number = std::to_string(sum2/10 + (k + (i - 1))/i);
            std::cout<<number[(k - 1) % i]<<'\n';
            break;
        }
    }
    return ;
}
int main() {
    uint64_t q, k; 
    std::cin>>q;
    for(uint64_t i = 0; i < q and std::cin >> k; ++i) {
        search(k);
    }
    return 0;
}