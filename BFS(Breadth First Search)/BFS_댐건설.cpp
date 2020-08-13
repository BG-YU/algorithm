/*
아래 배열을 초기화 해 주세요, 0으로된 지역은 벽 이고, 숫자는 물이 고여있는 양을 뜻합니다.
물 지역끼리 위,아래,왼쪽,오른쪽 중 하나가 연결 되어 있으면 서로 물이 흐를 수 있습니다.

0 5 4 3 0
3 2 5 4 1
0 1 0 1 0
3 1 9 7 1
2 0 0 2 3


여기서 물이 있는 두 지역을 선택하여, 그곳에 댐을 설치하려고 합니다.
만약 (3, 1) 지역과 (2, 3) 지역에 댐을 설치한다고 하면 아래와 같이 되고, 세 지역으로 나뉩니다.

0 5 4 3 0
3 2 5 4 1
0 1 0 0 0
3 0 9 7 1
2 0 0 2 3

[입력]
댐을 설치할 위치 Y, X 좌표 두개를 입력 받으세요.

[출력]
나뉘어져 있는 영역들에서 가장 많이 고여있는 물의 양을 출력하세요.

[입력 예제]
3 1
2 3

[출력 결과]
28
*/
#include <iostream>
using namespace std;

struct node {
	int y, x;
};

int map[5][5] = {
		0,5,4,3,0,
		3,2,5,4,1,
		0,1,0,1,0,
		3,1,9,7,1,
		2,0,0,2,3
};
int visit[5][5];

int bfs(int y, int x) {
	int sum = 0;
	int head = 0;
	int tail = 0;
	int direct[4][2] = {
		-1,0,
		0,-1,
		0,1,
		1,0
	};
	node queue[100];
	queue[tail++] = { y,x };

	while (head != tail) {
		node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= 5 || dx >= 5) continue;
			if (map[dy][dx] == 0) continue;
			if (visit[dy][dx] == 1) continue;
			visit[dy][dx] = 1;
			sum += map[dy][dx];
			queue[tail++] = { dy,dx };
		}
	}

	return sum;
}

int main() {
	int n1, n2, n3, n4;
	int maxx = -21e8;
	cin >> n1 >> n2 >> n3 >> n4;
	map[n1][n2] = 0;
	map[n3][n4] = 0;

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			if (visit[i][k] != 1 && map[i][k] != 0) {
				int ret = bfs(i,k);
				if (maxx < ret) {
					maxx = ret;
				}
			}
		}
	}

	cout << maxx;

	return 0;
}