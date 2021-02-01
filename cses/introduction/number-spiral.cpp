#include<iostream>

int main() {
	int t; std::cin >> t;
	uint64_t x, y;
	for(; t > 0; --t){
		std::cin >> x >> y;
		if (x >= y and !(x & 1)){
			std::cout << x * x - y + 1 << '\n';
		} else if(x >= y and (x & 1)){
			std::cout << (x - 1) * (x - 1) + y << '\n';
		} else if(x < y and ! (y & 1)){
			std::cout << y * y - 2 * y  + x + 1 << '\n';
		} else {
			std::cout << (y - 1) * (y - 1) + 2 * y - x << '\n';
		}

	}
}
