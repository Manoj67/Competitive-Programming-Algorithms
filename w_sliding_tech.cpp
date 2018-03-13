/* Given an array of integers of size �n�.
Our aim is to calculate the maximum sum of �k�
consecutive elements in the array using WINDOW SLIDING TECHNIQUE */

#include <iostream>
#include <string>

using namespace std;

int maxSum(int *arr, int n, int k){

	if(n < k){ // n must be greater than k
		return -1;
	}

	int max_sum = 0;
	for(int i = 0; i < k; ++i){ // sum of first k consecutive elements
		max_sum += arr[i];
	}

	// Compute sums of remaining windows by removing first element of previous window and adding last element of current
	// window.

    int window_sum = max_sum;

    for(int i = k; i < n; ++i){
		window_sum += arr[i] - arr[i-k];
		max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main(){
	int n;  // size of array
	cin >> n;

	int arr[n];

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	int k; // consecutive elements in the array
	cin >> k;

	cout << maxSum(arr, n, k);
}
