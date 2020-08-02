/*
다음 인접행렬에서 섬의 갯수와 가장 큰 섬의 크기 가장 작은 섬의 크기를 구하시오
1로 연결되어진 곳은 하나의 섬의로 간주한다.
상하좌우로 연결된 곳만 같은 섬으로 간주한다.
(대각선은 제외)
배열한칸 한칸이 섬의 크기이다.

입력
0,0,0,0,1,0,
0,1,0,0,1,0,
0,1,0,0,0,0,
0,1,1,0,1,1,
1,0,0,0,0,0

출력
4 4 1
*/

#include <iostream>
using namespace std;

struct Node {
	int y, x;
};

int map[5][6] = {
	0,0,0,0,1,0,
	0,1,0,0,1,0,
	0,1,0,0,0,0,
	0,1,1,0,1,1,
	1,0,0,0,0,0
};

int visit[5][6];

int direct[5][2] = {
	-1,0,
	0,-1,
	1,0,
	0,1,
	0,0
};

int bfs(int st_y, int st_x) {
	int head = 0;
	int tail = 1;
	int cnt = 0;
	Node queue[100];
	queue[head] = { st_y, st_x };

	while (head != tail) {
		Node now = queue[head++];

		for (int i = 0; i < 5; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;

			if (dy < 0 || dx < 0 || dy > 4 || dx > 5) continue;
			if (visit[dy][dx] == 1) continue;
			if (map[dy][dx] == 0) continue;
			queue[tail++] = { dy, dx };
			map[dy][dx] = 0;
			visit[dy][dx] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int maxx = -21e8;
	int minn = 21e8;
	int vis = 0;

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 6; k++) {
			if (visit[i][k] == 0 && map[i][k] == 1) {
				int ret = bfs(i, k);
				if (ret > maxx) maxx = ret;
				if (ret < minn) minn = ret;
				vis++;
			}
		}
	}

	cout << vis << " " << maxx << " " << minn;
	return 0;
}
