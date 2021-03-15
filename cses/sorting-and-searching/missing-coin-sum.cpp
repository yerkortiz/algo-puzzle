#include<iostream>
#include<vector>
#include<algorithm>

int main() { 
    uint64_t n; std::cin>>n;
    std::vector<uint64_t> integer_vector;
    for(int x; n > 0 and std::cin>>x; --n) {
        integer_vector.push_back(x);
    }
    n = integer_vector.size();
    std::sort(integer_vector.begin(), integer_vector.end());
    uint64_t s = 1; 
    for (uint64_t i = 0; i < n and integer_vector[i] <= s; i++) {
        s += integer_vector[i]; 
    }
    std::cout<<s;
    return 0; 
} 
