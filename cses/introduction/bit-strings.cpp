#include <iostream> 

int main(){
    long long nMod =  1e9 + 7;
    long long n; 
    std::cin >> n;
    long long sol = 1;
    for(long long i = 0; i < n; ++i) {
        sol <<= 1;
        sol %= nMod;
    }
    std::cout<<sol;
    return 0;
}