#include <iostream>
#include <cmath>
using namespace std;

// A function to print all prime factors of a given number n
void primeFactor(int n){
	// Print the number of 2s that divide n

	while(n%2 == 0){
		cout << 2 << " ";
		n = n/2;
	}

	// // Print the number of other prime(3, 5, .....) that divide n

	for(int i = 3; i <= sqrt(n); i+=2 ){

		while(n%i == 0){
			cout << i << " ";
			n = n/i;
		}

	}
	// This condition is to handle the case when n
    // is a prime number greater than 2 (e.g. 1025 gives 5 5 41)
	if(n>2)
		cout << n << " ";
}

int main(){
	int n;
	cin >> n;
	primeFactor(n);
}
