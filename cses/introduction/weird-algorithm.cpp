#include <iostream>
int main(){
  std::ios_base::sync_with_stdio(false);
  uint64_t n; std::cin >> n;
  while(n > 1) {
    std::cout<<n<<' ';
    if(n & 1) {
      n = ((3 * n) + 1);
    } else {
      n >>= 1;
    }
  }
  std::cout<<n<<'\n';
  return 0;
}

