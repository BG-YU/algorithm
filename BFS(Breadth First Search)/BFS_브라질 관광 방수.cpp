/*
브라질에 있는 mincerding 댐은 2대로 구성되어 있고,
63빌딩보다 15배 더 큰사이즈입니다.

관광을 사람들을 위해, 물을 모았다가 한번에 방수를 하려고 합니다.
지도에는 2개의 댐이 표시되어있고, 물의 최대 높이가 적혀있습니다.

한 댐에서 방수를하면 위 아래 왼쪽 오른쪽 방향으로 물이 1씩 줄어들면서 퍼져나갑니다.

안전사고를 예방하기 위해, 방수 결과를 미리 확인해보려고 합니다.
댐 계획지도를 입력받고, 방수 결과를 출력 해 주세요.
지도에는 물의 최대 높이를 기록해주시면 됩니다.

[세부사항]
1. 댐 지도 사이즈 : 1 <= N <= 10
2. 실제로 브라질에 mincerding이라는 댐은 없습니다.
3. 한 장소에 높이가 다른 물이 들어온다면, 최대 높이를 적습니다.
4. 물의 최대 높이는 9 입니다. 최소 높이는 1 입니다.
5. 댐은 항상 2개입니다.

[입력 예제]
10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 5 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 6 0
0 0 0 0 0 0 0 0 0 0

[출력 결과]
0 0 0 0 1 0 0 0 0 0
0 0 0 1 2 1 0 0 0 0
0 0 1 2 3 2 1 0 0 0
0 1 2 3 4 3 2 1 1 0
1 2 3 4 5 4 3 2 2 1
0 1 2 3 4 3 2 2 3 2
0 0 1 2 3 2 2 3 4 3
0 0 0 1 2 2 3 4 5 4
0 0 0 1 2 3 4 5 6 5
0 0 0 0 1 2 3 4 5 4
*/

#include <iostream>
#include <vector>

using namespace std;

int map[10][10];

void bfs(int y1, int x1, int y2, int x2, int w1, int w2, int limit) {
	struct node {
		int y1, x1, w1;
		int y2, x2, w2;
	};
	int direct[4][2] = {
		-1,0,
		1,0,
		0,-1,
		0,1
	};
	int head = 0, tail = 0;

	node queue[10000];
	queue[tail++] = { y1,x1,w1,y2,x2,w2 };

	while (head != tail) {
		node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			int dy1 = direct[i][0] + now.y1;
			int dx1 = direct[i][1] + now.x1;

			if (limit <= dy1 || 0 > dy1 || limit <= dx1 || 0 > dx1) continue;
			if (map[dy1][dx1] >= now.w1) continue;
			if (now.w1 == 0) continue;

			map[dy1][dx1] = now.w1 - 1;
			queue[tail++] = { dy1,dx1,now.w1 - 1 };
		}

		for (int i = 0; i < 4; i++) {
			int dy2 = direct[i][0] + now.y2;
			int dx2 = direct[i][1] + now.x2;

			if (limit <= dy2 || 0 > dy2 || limit <= dx2 || 0 > dx2) continue;
			if (map[dy2][dx2] >= now.w2) continue;
			if (now.w2 == 0) continue;

			map[dy2][dx2] = now.w2 - 1;
			queue[tail++] = { dy2,dx2,now.w2 - 1 };
		}
	}
}

int main() {
	struct node {
		int y, x, w;
	};
	vector<node> vect;

	int n, temp, y, x, w;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> temp;
			map[i][k] = temp;
			if (temp > 0) {
				vect.push_back({ i,k,temp });
			}
		}
	}

	bfs(vect[0].y, vect[0].x, vect[1].y, vect[1].x, vect[0].w, vect[1].w, n);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << map[i][k] << " ";
		}
		cout << endl;
	}

	return 0;
}