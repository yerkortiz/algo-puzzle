#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
int main() {
    std::string str; 
    std::cin >> str;
    std::vector<std::string> vctr;
    sort(str.begin(), str.end());
    do 
        vctr.push_back(str); 
    while (next_permutation(str.begin(), str.end()));
    std::cout << vctr.size() << "\n";
    for (std::string &str : vctr) 
        std::cout << str << "\n";
    return 0;
}