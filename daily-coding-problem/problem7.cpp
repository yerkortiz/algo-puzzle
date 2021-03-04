#include <iostream>
#include <string>

int countWays(std::string encoded_string, int n) {
	if (n == 0 || n == 1)
		return 1;
	int count = 0; 
	if (encoded_string[n - 1] > '0')
		count = countWays(encoded_string, n - 1);
	if (encoded_string[n - 2] == '1' || (encoded_string[n - 2] == '2' && encoded_string[n - 1] < '7'))
		count += countWays(encoded_string, n - 2);
	return count;
}

int countWaysDP(std::string encoded_string, int n) {
    int table[n+1] = {}; 
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (encoded_string[i-1] > '0')
            table[i] = table[i-1];
        if (encoded_string[i-2] == '1' || (encoded_string[i-2] == '2' && encoded_string[i-1] < '7') )
            table[i] += table[i-2];
    }
    return table[n];
}

int main() {
	std::string encoded_string;
    std::cin>>encoded_string;
	int n = encoded_string.size();
	std::cout << countWaysDP (encoded_string, n);
	return 0;
}
