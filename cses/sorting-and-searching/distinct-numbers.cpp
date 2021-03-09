#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n; 
    std::cin>>n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i)
        std::cin>>v[i];
    std::sort(v.begin(), v.end());
    int count = 1;
    for(int i = 1; i < n; ++i){
        if(v[i - 1] == v[i]) continue;
        ++count;
    }
    std::cout<<count<<'\n';
    return 0;
}