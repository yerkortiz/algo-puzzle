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
    int n, sum, i, j, k; std::cin >> n >> sum;
    bool solution = false;
    vctr_t v(n);
    for(i = 0; i < n; ++i){
        std::cin >> k;
        v[i].F = i + 1;
        v[i].S = k;
    }
    std::sort(v.begin(), v.end(), compare);
    for(i = 0, j = n - 1; i < j;) {
        //cout<<v[i].S<<' '<<v[j].S<<' '<<sum<<'\n';
        if(v[j].S >= sum) --j;
        if(v[j].S + v[i].S == sum) {
            solution = true;
            break;
        }
        else if(v[j].S + v[i].S < sum)
            ++i;
        else
            --j;
    }
    if(solution)
        std::cout<<v[i].F<<' '<<v[j].F<<'\n';
    else
        std::cout<<"IMPOSSIBLE\n";
    return 0;
}