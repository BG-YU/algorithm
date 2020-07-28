/*
2차원 배열의 그릴에 불을 놓을 수 있는 공간은 0, 불을 놓을 수 없는 공간은 1로 입력됩니다.
고기를 맛있게 굽기위해 불을 처음 놓을 좌표를 입력 받으세요.
불이 상, 하, 좌, 우로 한 칸씩 늘어날때마다 1초가 경과합니다.
불이 모든 자리에 붙었을때의 시간을 출력하세요.

2차원 배열에서 (0, 4)에 불을 놓는다면 2차원 배열안의 모든 0에 불이 퍼질때 까지 걸리는 시간은 8초입니다.

[2차원 배열]
1 0 0 0 0
1 0 1 0 1
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0

[입력]
그릴의 세로, 가로 길이 N 을 입력 받습니다. (3 <= n < 1,000)
그릴의 정보가 입력 됩니다.
그리고 불이 처음 놓일 좌표 Y X 가 입력됩니다.

[출력]
모든 '0' 자리에 불이 번지는데 걸리는 시간을 출력하세요.

[입력 예제]
5 5
1 0 0 0 0
1 0 1 0 1
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
0 4

[출력 결과]
8
*/

#include <iostream>
using namespace std;

struct Node {
	int y, x, sec;
};

int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};

int main() {
	int y, x, n1,n2,sec;
	int map[10][10];

	cin >> n1 >> n2;

	for (int i = 0; i < n1; i++) {
		for (int k = 0; k < n2; k++) {
			cin >> map[i][k];
		}
	}

	cin >> y >> x;

	int head = 0, tail = 1;
	Node node[100];
	node[head].y = y;
	node[head].x = x;
	node[head].sec = 0;

	while (head != tail) {
		Node temp = node[head++];

		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + temp.y;
			int dx = direct[i][1] + temp.x;

			if (dy < 0 || dx < 0 || dy > n1 - 1 || dx > n2 - 1) continue;
			if (dy == y && dx == x) continue;
			if (map[dy][dx] > 0) continue;

			node[tail].y = dy;
			node[tail].x = dx;
			node[tail].sec = node[head - 1].sec + 1;
			map[dy][dx] = node[tail].sec;
			sec = node[tail].sec;
			tail++;
		}
	}

	cout << sec;

	return 0;
}