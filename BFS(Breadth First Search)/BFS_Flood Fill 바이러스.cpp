/*
바이러스를 투여하고, 바이러스가 모두 퍼지고 난 뒤의 결과를 출력해주세요.
바이러스는 두 곳에 투여되며, 상, 하, 좌, 우 네 방향으로 퍼지게 됩니다.
바이러스가 퍼지는 맵의 크기는 3 X 3 입니다.

[입력]
바이러스가 투여되는 좌표 Y X 두곳을 입력하세요.

[출력]
바이러스가 모두 퍼지고 난 뒤의 상태를 출력해주세요.

[예시 1]
(0, 0) 과 (2, 2) 에 바이러스를 투여한다면 아래처럼 바이러스는 상하좌우 네 방향으로 퍼지며, 강도는 1씩 증가합니다.
(0, 0) 과 (2, 2) 에서 바이러스가 모두 퍼지면 위와 같은 결과가 출력되어야 합니다.

[입력 예제]
0 0
2 2

[출력 결과]
123
232
321
*/
#include <iostream>
using namespace std;

int main() {
	struct Node {
		int y, x;
		int lv;
	};
	int map[3][3] = {0};
	int head = 0;
	int tail = 0;
	int direct[4][2] = { -1,0,0, -1,1,0,0,1 };
	char chr[4];
	Node queue[50];
	
	for (int i = 0; i < 2; i++) {
		cin.getline(chr, 4);
		int y = chr[0] - '0';
		int x = chr[2] - '0';
		map[y][x] = 1;
		queue[tail++] = { y,x,1 };
	}

	while (head != tail) {
		Node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;

			if (dy < 0 || dx < 0 || dy > 2 || dx > 2) continue;
			if (map[dy][dx] > 0) continue;
			map[dy][dx] = now.lv + 1;
			queue[tail++] = {dy, dx,now.lv + 1};
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cout << map[i][k];
		}
		cout << '\n';
	}

	return 0;
}