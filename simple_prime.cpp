#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){
	if(n<2)
		return false;
	for(int i = 2; i*i <= n; ++i){
		if(n%i == 0)
			return false; // composite
	}
	return true; // prime
}

int main() {
	int a, b; // cout prime no. between a to b
	cin >> a >> b;
	while(a<=b){
		if(prime(a)){
			cout << a << endl;
		}
		a++;
	}
}
