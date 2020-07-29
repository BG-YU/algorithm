/*
세 종류의 동전이 있습니다.
교환할 지폐의 금액을 입력 받아주세요
위 동전으로 최소 몇 개의 동전을 거슬러 줄 수 있는지,
최소 수량을 구해 출력하세요.

동전 : 10원, 40원, 60원

예로들어 80원을 거슬러 주기 위해서는 40원짜리 동전 2개로 거슬러 줄 수 있습니다.

[입력 예제]
80

[출력 결과]
2
*/
#include <iostream>
using namespace std;

int arr[3] = { 10,40,60 };
int minn = 21e8;

void dfs(int lv, int sum) {
	if (sum == 0) {
		if (minn > lv) minn = lv;
		return;
	}

	if (sum < 0) return;

	for (int i = 0; i < 3; i++) {
		dfs(lv + 1, sum - arr[i]);
	}
}

int main() {
	int num;
	cin >> num;
	dfs(0, num);
	cout << minn;
	return 0;
}