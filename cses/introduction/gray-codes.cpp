#include <iostream>
#include <string>
int main() {
    int n;
    std::cin>>n;
    for(long long i = 0; i < (1 << n); ++i){
        std::string binary = std::bitset<16>(i ^ (i >> 1)).to_string();
        std::cout<<binary.substr(15 - n + 1, 15)<<'\n';
    }
}