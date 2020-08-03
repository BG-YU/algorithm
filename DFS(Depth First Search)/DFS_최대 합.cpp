/*
숫자 4개를 입력 받고 각각 *3,/2,-5를 했을 경우,
가장 큰 합의 수는 얼마인가?
*/

#include <iostream>
using namespace std;

int arr[4];
int maxx = -21e8;

void dfs(int lv, int num) {
	if (lv == 4) {
		if (maxx < num) maxx = num;
		return;
	}

	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 0:
			dfs(lv + 1, num + (arr[lv] * 3));
			break;
		case 1:
			dfs(lv + 1, num + (arr[lv] / 2));
			break;
		case 2:
			dfs(lv + 1, num + (arr[lv] - 5));
			break;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	cout << maxx;
	return 0;
}