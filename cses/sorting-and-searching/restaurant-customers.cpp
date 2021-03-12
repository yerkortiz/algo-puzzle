#include <iostream>
#include <vector>
#include <algorithm>
 
typedef std::vector<long long> vctr_t;
 
int main(void) {
    long long n, i, j; std::cin >> n;
    vctr_t arrive(n), leave(n);
    for(i = 0; i < n; ++i)
        std::cin >> arrive[i] >> leave[i];
    sort(arrive.begin(), arrive.end());
    sort(leave.begin(), leave.end());
    long long max = 0, cont = 0;
    for(i = 0, j = 0; i < n;) {
        if(arrive[i] < leave[j]){
            ++i; ++cont;
        } else if(arrive[i] > leave[j]) {
            ++j; --cont;
        } else {
            ++i; ++j;
        }
        if(cont >= max)
            max = cont;
    }
    std::cout << max <<'\n';
    return 0;
}