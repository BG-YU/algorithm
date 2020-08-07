/*
시작 좌표에서 종료 좌표까지 최소 몇 회만에 갈 수 있는지 확인해주세요.
BFS 알고리즘을 사용하여 길을 찾아주세요.

아래 1의 위치로는 이동할 수 없습니다.

0000
1101
0000
1010

[입력]
시작 좌표 Y X 와, 그 다음 줄에 종료 좌표 Y X 를 입력하세요.

[출력]
시작 좌표 부터 종료 좌표까지 최소 몇번 만에 도착할 수 있는지 출력해주세요.

[예시 1]
시작 좌표 (0, 0) 과 도착 좌표 (3, 3) 이 입력 될때, 결과는 6회입니다.

[입력 예제]
0 0
3 3

[출력 결과]
6회
*/
#include <iostream>
using namespace std;

int main() {
	int map[4][4] = {
		0,0,0,0,
		1,1,0,1,
		0,0,0,0,
		1,0,1,0
	};

	int direct[4][2] = {
		-1,0,
		0,-1,
		1,0,
		0,1
	};

	char chr[4];
	int head = 0;
	int tail = 0;
	int flag = 0;
	struct Node {
		int y, x, lv;
	};
	Node queue[50];
	cin.getline(chr, 4);
	queue[tail++] = { chr[0] - '0', chr[2] - '0', 1 };
	map[chr[0] - '0'][chr[2] - '0'] = 1;
	cin.getline(chr, 4);

	while (head != tail) {
		Node now = queue[head++];
		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;

			if (dy < 0 || dx < 0 || dx > 3 || dy > 3) continue;
			if (map[dy][dx] > 0) continue;

			map[dy][dx] = now.lv + 1;
			queue[tail++] = {dy,dx,now.lv + 1};

			if (dy == chr[0] - '0' && dx == chr[2] - '0') {
				flag = 1;
				break;
			}
		}

		if (flag == 1) break;
	}

	if (flag == 1) cout << (queue[tail - 1].lv) - 1 << "회";
}