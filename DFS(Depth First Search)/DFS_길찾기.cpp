/*
경우의수
출발가능 위치는 (0,0),(1,0),(2,0) 이고 도착은 (0,7),(1,7),(2,7) 일때
입력받은 출발위치에서 도착지점까지 이동 가능한 경우의 수는 몇가지 인가?

  0 1 2 3 4 5 6 7
A □□□□□□□□
B ■□□□□□□□
C □□□□□□□□

7 = 도착점
0 = 출발점

[이동가능 경로]
대각선 오른쪽 위
오른쪽
대각산 오른쪽 아래

[입력값]
A

[출력값]
408
*/
#include <iostream>
using namespace std;

int direct[3][2] = {
	-1,1,
	0,1,
	1,1
};
int cnt;
void dfs(int y, int x) {
	if (x == 7) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int dy = direct[i][0] + y;
		int dx = direct[i][1] + x;

		if (dx < 0 || dy < 0 || dy > 2 || dx > 7) continue;
		dfs(dy, dx);
	}
}

int main() {
	char chr;
	cin >> chr;
	dfs(chr - 'A', 0);
	cout << cnt;
	return 0;
}