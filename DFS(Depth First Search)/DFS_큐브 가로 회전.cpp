/*
가로줄을 돌릴 수 있는 3x3 큐브가 있습니다.

3 7 4     4 3 7    4 3 7
5 4 6  -> 5 4 6 -> 6 5 4
1 3 6     1 3 6    1 3 6

큐브를 적절하게 돌려, 주어진 계산식의 결과값이 최대가 되도록 만들어 주세요.
이 큐브는 윗줄, 중간, 아랫줄을 돌리면 숫자의 위치가 변경됩니다.

최대 점수가 나오게끔 퍼즐을 돌리려고 합니다.
점수 계산 방법은 세로줄의 합을 각각 구하고, 아래 예제와 같이 점수를 구하면 됩니다.

[계산식]
첫번째 세로줄의 합 - 두번째 세로줄의 합 + 세번째 세로줄의 합

[예시]
(아래 예제는 최고점수는 아닙니다, 채점 결과의 예제입니다.)
4 + 6 + 1 = 11
3 + 5 + 3 = 11
7 + 4 + 6 = 17
11 - 11 + 17 = 17

퍼즐을 여러가지 방법으로 돌렸을때, 나올 수 있는 최대 점수를 출력 해주세요.

[입력]
3 x 3 의 큐브 값이 입력 됩니다.

[출력]
계산식에 맞게 계산한 결과가 가장 큰 값을 출력 해주세요.


[입력 예제]
4 3 7
5 4 6
6 1 3

[출력 결과]
23점
*/
#include <iostream>
#include <cstring>
using namespace std;

int map[3][3];
int maxx = -21e8;

void fn_change(int cnt) {
	int temp = map[cnt][0];
	for (int i = 1; i < 3; i++) map[cnt][i - 1] = map[cnt][i];
	map[cnt][2] = temp;
}

int fn_sum(int cnt) {
	int sum = 0;
	for (int i = 0; i < 3; i++) sum += map[i][cnt];
	return sum;
}

void dfs(int lv) {
	int backup[3][3];

	int sum = fn_sum(0) - fn_sum(1) + fn_sum(2);
	if (maxx < sum) maxx = sum;
	if (lv == 3) return;

	for (int i = 0; i < 3; i++) {
		memcpy(backup, map, 4 * 3 * 3);
		fn_change(i);
		dfs(lv + 1);
		memcpy(map, backup, 4 * 3 * 3);
	}
}


int main() {
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> map[i][k];
		}
	}

	dfs(0);
	cout << maxx << "점";
	return 0;
}