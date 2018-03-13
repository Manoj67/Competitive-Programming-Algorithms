#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(a == b)
		return a;
	if(a>b)
		return gcd(a-b, b);
	return gcd(a, b-a);
}

// a x b = LCM(a, b) * GCD (a, b)
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	int a, b;
	cin >> a >> b;

	int result = lcm(a,b);

	cout << result;
}
