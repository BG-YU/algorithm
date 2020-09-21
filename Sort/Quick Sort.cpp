#include<iostream>
#include<cstring>

using namespace std;

int arr[7] = { 6,1,7,4,2,9,4 };

void quick(int start, int end)
{
	if (start >= end) return;  // 트리 맨 밑

	int pivot = start;
	int a = pivot + 1;
	int b = end;

	while (1) {
		while (a <= end && arr[pivot] >= arr[a]) a++;
		while (b > pivot && arr[pivot] < arr[b]) b--;

		if (a > b)break;
		swap(arr[a], arr[b]);
	}
	swap(arr[b], arr[pivot]);

	quick(start, b - 1); // 왼쪽 오른쪽 호출
	quick(b + 1, end);

}
int main() {
	quick(0, 6);
	return 0;
}