/*
배달맨은 배달지역 가장 가까운 숫자를 향해 달려 갑니다.
여러개의 1 ~ 4번 배달지역이 있고, 배달맨은 순서대로 하나의 1, 2, 3, 4 번 지역을 한 번씩 들리면 됩니다.
각 배달지역은 중복되어 주어질 수 있습니다. 여러개의 배달지역 중 같은 숫자의 배달지역은 한 번만 들려도 됩니다.

배달맨의 출발 위치는 (0, 0) 입니다. 출발점 > 1 > 2 > 3 > 4 순서로 배달을 완료해야 합니다.
배달맨이 배달을 가장 빨리 끝낼 수 있는 시간을 출력해주세요

[배달 규칙]
배달맨은 배달 위치를 선택할때 현재 위치에서 가장 가까운 곳을 선택해야 합니다.
(0, 0) 에서 가장 가까운 1번 지역에 도착합니다.
그리고 도착한 1번 지역에서 가장 가까운 2번 지역에 도착합니다.
2번 지역에 도착하면, 가장 가까운 3번 지역에 도착합니다.
3번 지역에 도착하면, 가장 가까운 4번 지역에 도착합니다.

* 거리가 같은 경우는 입력으로 주어지지 않습니다.

[입력]
맵을 입력 받아 주세요. (3 x 5 사이즈)
숫자는 지나갈 수 있는 지역이고 # 은 이동할 수 없는 벽 입니다.

[출력]
배달맨이 가장 빠르게 배달을 완료할 수 있는 이동 횟수를 출력 해주세요.

[입력 예제]
30002
##4##
01024

[출력 결과]
15회
*/
#include <iostream>
#include <vector>
using namespace std;

vector<char> vect[3];
int used[4] = {1,2,3,4};
int used_cnt = 0;
int gy = 0, gx = 0;
struct Node {
	int y, x, lv;
};

int g_cnt = 0;

void bfs(int y, int x) {
	int visit[3][5] = { 0 };
	int head = 0;
	int tail = 0;
	int direct[4][2] = {
		-1,0,
		0,-1,
		1,0,
		0,1
	};
	Node queue[50];
	queue[tail++] = { y,x };

	while (head != tail) {
		Node now = queue[head++];
		for (int i = 0; i < 4; i++) {
			int dy = direct[i][0] + now.y;
			int dx = direct[i][1] + now.x;
			if (dy < 0 || dx < 0 || dy > 2 || dx > 4) continue;
			if (vect[dy][dx] == '#') continue;
			if (visit[dy][dx] == 1) continue;
			visit[dy][dx] = 1;
			queue[tail++] = { dy,dx, now.lv + 1};

			if (used[used_cnt] == vect[dy][dx] - '0') {
				used_cnt++;
				gy = dy;
				gx = dx;
				g_cnt = now.lv + 1;
				return;
			}
		}
	}
}

int main() {
	char temp[10];
	int cnt = 0;

	for (int i = 0; i < 3; i++) {
		cin.getline(temp, 10);
		for (int k = 0; k < 10; k++) {
			if (temp[k] == '\0') break;
			vect[i].push_back(temp[k]);
		}
	}

	for (int i = 0; i < 4; i++) {
		bfs(gy, gx);
		cnt += g_cnt;
		g_cnt = 0;
	}
	cout << cnt << "회";
	return 0;
}