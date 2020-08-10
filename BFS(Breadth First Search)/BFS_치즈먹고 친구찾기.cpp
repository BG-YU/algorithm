/*
쥐□□F■
■□■□□
C□□□■
C : 치즈
F : 친구
■ : 이동불가

(0, 0)에 서있는 쥐는 치즈를 먼저 먹고, 친구를 만나러 가려고 합니다.
쥐는 ↑↓ ← → 로 이동 할 수 있습니다.

[입력]
치즈 위치 (Y, X) 와 친구 좌표 (N, M) 을 입력 받으세요.

[출력]
친구를 만나기까지의 최단 거리를 출력 해주세요.
한 칸을 이동했을때가 1입니다.

[예시]
위 예제에서는 9회 이동으로 치즈를 먹고 친구를 만날 수 있습니다.


[입력 예제]
2 0
0 3

[출력 결과]
9
*/
#include <iostream>
using namespace std;

int map[3][5] = {
	0,0,0,0,1,
	1,0,1,0,0,
	0,0,0,0,1
};

struct Node {
	int y, x, cnt;
};

int bfs(int y, int x, int target_y, int target_x) {
	int visit[3][5] = { 0 };
	int direct[4][2] = {
		-1,0,0,-1,1,0,0,1
	};
	visit[y][x] = 1;
	int head = 0;
	int tail = 0;
	Node queue[50];
	queue[tail++] = { y,x,0 };

	while (head != tail) {
		Node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;
			if (dy < 0 || dx < 0 || dy > 2 || dx > 4) continue;
			if (map[dy][dx] == 1) continue;
			if (visit[dy][dx] == 1) continue;
			visit[dy][dx] = 1;
			queue[tail++] = { dy,dx,now.cnt + 1 };
			if (dy == target_y && dx == target_x) {
				return now.cnt + 1;
			}
		}
	}
	return -1;
}

int main() {
	int cnt = 0;
	int y1, x1,y2,x2;

	cin >> y1 >> x1 >> y2 >> x2;
	int ret = bfs(0, 0, y1, x1);
	cnt += ret;
	ret = bfs(y1, x1, y2, x2);
	cnt += ret;

	cout << cnt;
	return 0;
}