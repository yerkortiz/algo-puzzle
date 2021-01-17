#include <iostream>
#include <vector>

int main(){
  std::ios_base::sync_with_stdio(false);
  uint64_t n, count1 = 0; std::cin >> n;
  std::vector<int> v(n);
  for(auto &i: v) {
    std::cin >> i;
  }
  for(std::vector<int>::iterator it = v.begin() + 1; it != v.end(); ++it) {
    if(*(it - 1) > *(it)) {
      count1 += (*(it - 1) - *(it));

      *(it) += (*(it - 1) - *(it));
     }
  }
  std::cout << count1 << '\n';
  return 0;
}
