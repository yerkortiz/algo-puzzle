#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define F first
#define S second
#define MP make_pair
#define PB push_back
typedef std::pair<int, int> pr_t;
typedef std::vector<pr_t> vctr_t;
bool compare(const std::pair<int, int>&i, const std::pair<int, int>&j) {
    return i.second < j.second;
}
int main(void) {
    int n, i, a, b; std::cin >> n;
    vctr_t movies(n);
    for(i = 0; i < n and std::cin >> a >> b; ++i) {
        movies[i].F = a;
        movies[i].S = b;
    }
    sort(movies.begin(), movies.end(), compare);
    int last_end = 0, cnt = 0;
    for(i = 0; i < n; ++i) 
        if(movies[i].F >= last_end){
            last_end = movies[i].S;
            ++cnt;
        }
    std::cout<<cnt<<'\n';
    return 0;
}