#include <iostream>
#include <algorithm>

using namespace std;

int BS(int *arr, int n,int key){
	int low = 0, high = n-1;

	while(low <= high){
		int mid = low + (high - low) / 2; // to avoid overflow

		if(key == arr[mid]) // if key is at mid (base case)
			return mid;
		else if(key < arr[mid]) // key lies before mid
			high = mid - 1;
		else
			low = mid + 1; // key lies after mid
	}
	return -1;
}
int main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	sort(arr, arr + n); // for binary search

	for(int i = 0; i < n; ++i){
		cout << arr[i];
	}

	int key;
	cin >> key;
	cout << "key is at position "<< BS(arr,n,key) << endl;
}
