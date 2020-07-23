/*
arr배열에서 입력받은 숫자를 BS로 검색
*/
#include <iostream>
using namespace std;

int arr[10] = { 4,4,5,7,8,10,20,22,23,24 };

int run(int num, int start, int end) {
	if (start > end) return 0;

	int mid = (start + end) / 2;
	if (arr[mid] == num) return 1;

	if (arr[mid] < num) run(num, mid + 1, end);
	else run(num, start, mid - 1);
}

int main() {
	int start = 0, end = 9;
	int num;

	cin >> num;

	int ret = run(num, start, end);

	if (ret == 1) cout << "O";
	else cout << "X";

	return 0;
}