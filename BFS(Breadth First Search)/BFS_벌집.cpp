/*
시골집에 벌들이 너무 많이 증식하여 골치를 앓고 있습니다.
벌들을 죽여도 소용이 없어 이장님은 여왕벌의 알집을 찾아 없애려고 합니다.

입력으로 4 x 9 벌집이 입력 됩니다. 벌집안의 숫자는 벌들의 신호 입니다.
어느 숫자가 알집을 나타내는 지는 이장님은 알 수 없지만,
같은 숫자가 가장 많이 붙어 있는 지역이 알집인 것을 알아 내셨습니다.

[ 알집은 상, 하, 좌, 우로만 붙어 있습니다. ]

[입력]
4 X 9 맵이 입력 됩니다.

[출력]
연속으로 붙어있는 숫자가 가장 많을때, 개수와 집의 값을 곱한 값을 출력하세요.

[입력 예제]
0 1 2 1 4 8 3 1 3
2 3 2 3 4 2 3 1 3
2 2 2 3 4 3 4 3 3
0 2 1 3 4 2 1 3 2

[출력 결과]
14
*/
#include <iostream>
#include <vector>
using namespace std;

int map[4][9];
int visit[4][9] = { 0 };
vector<int> vect;

int bfs(int y, int x, int num) {
	struct node { int y, x; };
	
	int head = 0;
	int tail = 0;
	int cnt = 0;
	int direct[5][2] = {
		-1,0,
		0,-1,
		1,0,
		0,1,
		0,0
	};
	node queue[50];
	queue[tail++] = { y,x };

	while (head != tail) {
		node now = queue[head++];
		for (int i = 0; i < 5; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;
			if (dy < 0 || dx < 0 || dy > 3 || dx > 8) continue;
			if (visit[dy][dx] == 1) continue;
			if (map[dy][dx] != num) continue;
			visit[dy][dx] = 1;
			cnt++;
			queue[tail++] = { dy,dx };
		}
	}

	return cnt;
}

int main() {
	int dat[100] = {0}, num, maxx = -21e8, tmp;
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> num;
			map[i][k] = num;
			dat[num]++;
		}
	}

	for (int i = 0; i < 100; i++) {
		if (dat[i] > 0) {
			vect.push_back(i);
		}
	}

	for (int i = 0; i < vect.size(); i++) {
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 9; j++) {
				if (vect[i] == map[k][j] && visit[k][j] != 1) {
					//visit[k][j] = 1;
					tmp = bfs(k, j, vect[i]);
					if (maxx < tmp) {
						maxx = tmp;
						num = vect[i];
					}
				}
			}
		}
	}

	cout << maxx * num;
	return 0;
}