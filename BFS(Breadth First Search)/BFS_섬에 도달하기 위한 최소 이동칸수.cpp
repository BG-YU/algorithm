/*
아래 지도에서 배가 섬에 정박하기 위해서는 최소 몇칸을 이동해야 하는가?
0 : 바다
1 : 섬
2 : 배
(배는 2가 2개 연결되어 하나의 배로 인식)

0,1,1,0,1
0,0,0,0,1
0,0,0,1,1
2,0,0,0,1
2,0,0,0,1
*/

#include <iostream>
using namespace std;

struct Node {
	int y, x, lv;
};

Node queue[100];
int head = 0, tail = 0;

int map[5][5] = {
	0,1,1,0,1,
	0,0,0,0,1,
	0,0,0,1,1,
	2,0,0,0,1,
	2,0,0,0,1,
};
int visit[5][5] = { 0 };
int direct[4][2] = {
	1,0,0,1,-1,0,0,-1
};

int bfs() {
	while (head != tail) {
		Node now = queue[head++];
		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;
			if (dy < 0 || dx < 0 || dy > 4 || dx > 4) continue;
			if (visit[dy][dx] == 1) continue;
			visit[dy][dx] = 1;
			queue[tail++] = { dy,dx,now.lv + 1 };
			if (map[dy][dx] == 1) return now.lv + 1;
		}
	}

	return -1;
}

int main() {
	for (int i = 0; i < 5; i++){
		for (int k = 0; k < 5; k++) {
			if (map[i][k] == 2) {
				queue[tail++] = {i,k,0};
				visit[i][k] = 1;
			}
		}
	}

	cout << bfs();
	return 0;
}