/*
* https://cses.fi/problemset/task/1072
*/
#include <iostream>
#include <cmath>
int main(){
    long long t; std::cin>>t;
    for(long long n = 1; n <= t; ++n) {
      std::cout<<(long long)((pow(n, 4) - 9 * pow(n, 2) + 24 * n - 16)/2)<<'\n';
    }
    return 0;
}
