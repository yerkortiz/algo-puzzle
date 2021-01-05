#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> m;
      std::vector<int> vect;
      int j = 0;
      for(const auto& it: nums) {
        if(m.find(target - it) != m.end() and m[target - it] != j) {
          vect.push_back(m[target-it]);
          vect.push_back(j);
          return vect;
        }
        m[it] = j++;
      }
      return vect;
    }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, target; std::cin >> n >> target;
  std::vector<int> nums(n);
  for(int i = 0; i < n && std::cin >> nums[i]; i++);
  Solution *s = new Solution;
  auto v = s -> twoSum(nums, target);
  for(const auto&it:v){
    std::cout<<it<<' ';
  }
  /*std::unordered_map<int, int> m;
  j = 0;
  for(const auto& it: nums) {
    if(m.find(target - it) != m.end() and m[target - it] != j) {
      std::cout <<j<< ' '<<m[target - it]<<'\n';
      break;
    }
    m[it] = j++;
  }*/
  return 0;
}
