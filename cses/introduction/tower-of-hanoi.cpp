#include <iostream>

void towerOfHanoi(int n, char src, char dst, char tmp) { 
	if (n == 1) { 
		std::cout << src << " " << dst << "\n"; 
		return; 
	} 
	towerOfHanoi(n - 1, src, tmp, dst); 
	std::cout << src << " " << dst << "\n"; 
	towerOfHanoi(n - 1, tmp, dst, src); 
} 
int main() { 
    int n;
	std::cin>>n;
    std::cout<< uint64_t((1u << n) - 1u)  <<"\n";
	towerOfHanoi(n, '1', '3', '2'); 
	return 0; 
} 
