#include <iostream> 
int main(){
  std::string dna; std::cin>>dna;
  uint64_t current_length = 1, max_length = 1; 
  for(std::string::iterator it = dna.begin() + 1; it != dna.end(); ++it){
    if(*(it) == *(it - 1)){
      current_length++;
      if(current_length >= max_length) {
        max_length = current_length;
      }
    } else {
      current_length = 1;
    }
  }
  std::cout<<max_length<<'\n';
  return 0;
}
