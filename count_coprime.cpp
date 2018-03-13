// C program to calculate Euler's Totient Function
#include <iostream>
#include <cmath>

using namespace std;

int phi (int n) {
	int result = n;

	// Consider all prime factors of n and subtract their
    // multiples from result
	for (int i=2; i<=sqrt(n); ++i){
		// Check if i is a prime factor
		if (n % i == 0) {
			// If yes, then update n and result
			while (n % i == 0)
				n /= i;

			result -= result / i;
		}
	}
	 // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
	if (n > 1)
		result -= result / n;
	return result;
}

int main(){
	for(int i = 1; i <=10; ++i){
		cout << i << "="  << phi(i) << endl;
	}
}
