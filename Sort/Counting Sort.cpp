/*
Count Sort
*/
#include<iostream>
using namespace std;

int main(){
	int arr[5] = { 2,2,1,5,7 };
	int bucket[10] = { 0 };
	int result[10] = { 0 };

	for (int x = 0; x < 5; x++){
		bucket[arr[x]]++;
	}
	
	for (int x = 1; x < 10; x++){
		bucket[x] += bucket[x - 1];
	}

	for (int x = 0; x < 5; x++){
		int t = arr[x];
		result[bucket[t]--] = arr[x];
	}

	for (int x = 1; x < 6; x++){
		cout << result[x];
	}

	return 0;
}