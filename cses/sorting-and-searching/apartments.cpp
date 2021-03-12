#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
 
typedef std::vector<int> vctr_t;
 
int main(void) {
    int n, m, k;
    std::cin >> n >> m >> k;
    vctr_t wished_size(n), current_size(m);
    int i, j, c;
    for(i = 0; i < n and std::cin >> wished_size[i]; ++i)
        ;
    for(j = 0; j < m and std::cin >> current_size[j]; ++j)
        ;
    sort(wished_size.begin(), wished_size.end());
    sort(current_size.begin(), current_size.end());
    for(i = 0, j = 0, c = 0; i < n and j < m;) {
        if(abs(wished_size[i] - current_size[j]) <= k) {
            ++j; ++c; ++i;
        } else if(wished_size[i] > current_size[j]){
            ++j;
        } else {
            ++i;
        }
    }
    std::cout << c << '\n';
    return 0;
}