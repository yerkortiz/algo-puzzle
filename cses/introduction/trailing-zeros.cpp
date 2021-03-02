/*
* https://cses.fi/problemset/task/1618
*/
#include <iostream>
typedef long long long_t;
int main() {
    long_t n; 
    std::cin>>n;
    long_t k = 5;
    long_t cont = 0;
    while(n / k > 0) {
        cont += (n / k);
        k *= 5;
    }
    std::cout<<cont<<'\n';
    return 0;
}