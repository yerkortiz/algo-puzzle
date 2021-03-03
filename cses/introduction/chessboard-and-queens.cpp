#include <iostream>

int cont = 0, n = 8;
int col[8] = {0}, diag1[15] = {0}, diag2[15]={0};
std::string arr[8];
void solution(int y) {
    if(y == n) {
        cont++;
        return;
    } 
    for(int x = 0; x < n; ++x) {
        if(arr[x][y] == '*') continue;
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        solution(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}
int main() {
    for(int i = 0; i < 8; ++i)
        std::cin>>arr[i];
    solution(0);
    std::cout<<cont<<'\n';
    return 0;
}