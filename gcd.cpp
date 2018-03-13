#include <iostream>

using namespace std;
// Euclid's Algorithm
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

/*
for (int i=min(a,b); i>=1; i--)
   if (a%i==0 && b%i==0)
      return i;

*/
int main(){
	int a, b;
	cin >> a >> b;

	int result = gcd(a,b);

	cout << result;
}

// a*b = gcd(a,b) *lcm(a,b);
