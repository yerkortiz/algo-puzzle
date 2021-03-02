#include <iostream>
#include <set>
#include<vector>
int main() {
  long long n, s;
  std::cin>>n;
  s = ((n)*(n + 1)/2);
  if (s & 1) {
    std::cout<<"NO\n";
    return 0;
  }
  std::set<long long> integer_set;
  std::set<long long>::iterator it = integer_set.end();
  for(int i = 1; i <= n; ++i) 
    integer_set.insert(it, i);
  s /= 2;
  std::vector<long long> integer_vector;
  for(int i = n; s > 0 && i > 0; --i) {
    if(integer_set.find(i) != integer_set.end() && s >= i){
      s -= i;
      integer_vector.push_back(i);
      integer_set.erase(i);
    }
  }
  std::cout<<"YES\n"<<integer_vector.size()<<"\n";
  for(const auto& x: integer_vector){
    std::cout<<x<<' ';
  }
  std::cout<<"\n"<<integer_set.size()<<"\n";
  for(const auto& x: integer_set){
    std::cout<<x<<' ';
  }
  return 0;
}
