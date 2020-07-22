/*
2차원 배열 시계방향 회전

먼저 N과 K를 입력
사이즈가 N x N 인 배열입력

N = 배열사이즈
K = 회전횟수

[입력 예제]
5 1
1 0 1 0 1
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0
0 1 0 1 0

[출력 결과]
0 0 0 1 1
1 0 0 1 0
0 1 1 1 1
1 0 0 1 0
0 0 0 1 1
*/

#include <iostream>
using namespace std;

void fn_calc(int* y, int* x, int cnt, int n, int lv) {
	
	if (lv == cnt) return;

	int temp = *y;
	*y = *x; // x축을 y축으로 변경
	*x = n - temp; // y축을 x축으로 변경하면서 숫자 역순으로 뒤집기

	return fn_calc(y, x, cnt, n, lv + 1);
}

int main() {
	int n, k;
	int arr[100][100] = { 0 };
	int ret[100][100] = { 0 };
	int dy, dx;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) continue;
			dy = i;
			dx = j;
			fn_calc(&dy, &dx, k, n - 1, 0);
			ret[dy][dx] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}