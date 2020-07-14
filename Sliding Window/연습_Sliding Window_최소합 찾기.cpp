/*
숫자 n과 n개의 숫자를 입력 받아주세요. (4 <= n <= 100,000)
숫자 9를 입력받고, (n = 9)
7 2 4 3 2 1 1 9 2를 입력받으세요
배열에서 연속 되어있는 네 칸의 합을 구했을 때,
가장 작은 값이 몇 인지 출력 해 주세요

위 예제에서는 최소 합은 7 입니다. (3 + 2 + 1 + 1)
*/

#include <iostream>
using namespace std;

int main() {
	int num;
	int arr[100];
	int ret = 21e8;
	int sum = 0;

	cin >> num;

	for (int i = 0; i < num; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) sum += arr[i];
	for (int i = 0; i < num - 4; i++) {
		sum -= arr[i];
		sum += arr[i + 4];
		if (ret > sum) ret = sum;
	}

	cout << ret;

	return 0;
}