// Now let’s see how the two pointer technique works. We take two pointers, one representing the first element and other representing the last element of the array,
// and then we add the values kept at both the pointers.
// If their sum is smaller than X then we shift the left pointer to right or if their sum is greater than X then we shift the right pointer to left, in order to get closer to the sum.

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool isPairSum(int *arr, int n, int sum){
	int i = 0; // first pointer
	int j = n-1; // second pointer

	while (i<j) {
		if(arr[i] + arr[j] == sum)
			return true;
		else if(arr[i] + arr[j] < sum)
			i++;
		else
			j--;
	}
	return false;
}
int main(){
	int n; // size
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	int sum; // sum to find
	cin >> sum;
	int res =  isPairSum(arr, n, sum);
		if(res) // if found(true)
			cout << "found" << endl;
		else
			cout << "not found" << endl;

}

// The algorithm basically uses the fact that input array is sorted. We start sum of extreme values (smallest and largest) and conditionally move both pointers.
// We move left pointer i when sum of A[i] and A[j[ is less than X. We do not miss any pair because sum is already smaller than X. Same logic applies for right pointer j.
