/*
5개의 항에 숫자를 채우려고 합니다.

□ x □ - □ x □ + □

숫자 5개를 입력받고, 최고의 위치를 선정 해 주세요. (-10 <= 숫자 <= 10)
만들어질 수 있는 최댓값과 최솟값을 Backtracking을 이용하여 구해주세요.
(연산자 우선순위를 지켜주세요, 곱셈은 뺄셈보다 우선합니다.)

만약 1 2 3 4 5를 입력받았다면
최댓값 = (5 x 4) - (2 x 1) + 3 = 21
최솟값 = (3 x 1) - (5 x 4) + 2 = -15


[입력 예제]
1 2 3 4 5

[출력 결과]
21
-15
*/
#include <iostream>
using namespace std;

int arr[5];
int path[5];
int used[5];
int maxx = -21e8, minn = 21e8;
void dfs(int lv) {
	if (lv == 5) {
		int calc = (path[0] * path[1]) - (path[2] * path[3]) + path[4];
		if (maxx < calc) maxx = calc;
		if (minn > calc) minn = calc;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lv] = arr[i];
		dfs(lv + 1);
		path[lv] = 0;
		used[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 5; i++) cin >> arr[i];
	dfs(0);
	cout << maxx << endl;
	cout << minn;
	return 0;
}