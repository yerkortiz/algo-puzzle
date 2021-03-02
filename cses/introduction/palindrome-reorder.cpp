#include <iostream>
#include <vector>
#include <string>
int main() {
    std::string str; 
    std::cin >> str;
    std::vector<int> table(26);
    for(int i = 0; i < str.size(); ++i)
        ++table[str[i] - 'A'];
    int odd_c = 0, even_c = 0;
    char odd_char;
    for(int i = 0; i < 26; ++i){
        if(table[i] && (table[i] & 1)) {
            odd_char = (i + 'A');
            ++odd_c;
        } else if(table[i] && !(table[i] & 1)) {
            ++even_c;
        } 
    }
    if(odd_c < 2) {
        std::string str_palindrome(str.size(), ' ');
        for(int j = 0, i = 0; j < 26 && i < str.size()/2;) {
            if((table[j] & 1) && table[j] > 1){
                table[j] -= 2;
                str_palindrome[i] = (char) (j + 'A');
                str_palindrome[str.size() - i - 1] = (char) (j + 'A');
                ++i;
            } else if(! (table[j] & 1) && table[j] > 0) {
                table[j] -= 2;
                str_palindrome[i] = (char) (j + 'A');
                str_palindrome[str.size() - i - 1] = (char) (j + 'A');
                ++i;
            } else {
                ++j;
            }
        }
        if(odd_c) str_palindrome[str.size()/2] = odd_char;
        std::cout<<str_palindrome<<'\n';
    } else {
        std::cout<<"NO SOLUTION\n";
    }
    return 0;
}