#include <iostream>
#include <string>
#include <bitset>
int main() {
    int n;
    std::cin>>n;
    for(long long i = 0; i < (1 << n); ++i){
        std::string binary = std::bitset<16>(i ^ (i >> 1)).to_string();
        std::cout<<binary.substr(16 - n, 16)<<'\n';
    }
}