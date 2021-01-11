#include <iostream> 
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false); 
  uint64_t n, sum = 0, s = 0; std::cin>>n;
  std::vector<int> v(n - 1);
  sum = ((n * n) + n) / 2;
  for (auto i : v) {
    std::cin>>v[i];
    s += v[i];
  }
  std::cout<<sum - s<<'\n';
  return 0;
}
