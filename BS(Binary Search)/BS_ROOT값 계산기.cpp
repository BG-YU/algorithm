/*
입력 받은 값을 Binary Search 를 이용하여 루트 값의 정수부를 구해주세요.

만약 16 입력시 출력결과는 4 입니다.
만약 17 입력시 root 값은 4.xxx 이므로, 출력결과는 4 입니다.

만약 25 입력시 root 값은 5 입니다.
만약 35 입력시 root 값은 5.xxx 이므로, 출력결과는 5 입니다.

[입력]
숫자 값을 하나 입력 받습니다.

[출력]
입력 받은 값의 루트 값을 정수 부분만 출력 해주세요.
*/
#include <iostream>
using namespace std;

int arr[100];

int bs(int start, int end, int num) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (arr[mid] * arr[mid] <= num) {
		for (int i = end; i >= 1; i--) {
			if (arr[end] * arr[end] >= num && arr[i] * arr[i] <= num) return arr[i];
		}
	}
	return bs(start, mid, num);
}

int main() {
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		arr[i] = i;
	}

	cout << bs(0, num, num);

	return 0;
}