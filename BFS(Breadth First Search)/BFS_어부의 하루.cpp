/*
바다 낚시를 나간 어부는 레이더를 사용하여 물고기가 어느 위치에 있는지 알 수 있습니다.
배가 각 물고기를 잡으러 이동하는 거리를 계산하여 가까운 물고기 순서대로 좌표와 거리를 순서대로 출력 해주세요.

물고기를 잡기 위해서는 배를 이동시켜 물고기 위치까지 갔다가 원래 자리로 돌아 옵니다.
배는 암초를 통과할 수 없고, 배는 상, 하, 좌, 우로 이동할 수 있습니다.

[좌표 예시]
-1 0 1 0 0
0 0 1 0 -1
1 0 0 0 0
-1 0 0 1 0
0 0 -1 0 0

[예시]
(3, 3) 위치의 물고기는 배 바로 아래 위치하기 때문에 거리가 1입니다.
가장 먼 물고기들은 (0, 2) 와 (2, 0) 로 거리가 3입니다.

[입력]
배의 좌표 Y X가 입력 됩니다.
그후 5 X 5 크기의 바다 정보가 입력 됩니다.
0 은 빈공간, 1 은 물고기 위치, -1 은 암초 위치 입니다.

[출력]
배 좌표에서 가까운 물고기 순으로 물고기의 Y 좌표, X 좌표, 이동 거리를 출력 해주세요.
만일 물고기들의 거리가 같으면 Y 값이 작은 물고기 먼저 이후, X 값이 작은 순으로 출력 해주세요.


[입력 예제]
2 3
-1 0 1 0 0
0 0 1 0 -1
1 0 0 0 0
-1 0 0 1 0
0 0 -1 0 0

[출력 결과]
3 3 1
1 2 2
0 2 3
2 0 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct fish {
	int y, x, move;
};

vector<int> visit[5];
vector<int> vect[5];
vector<fish> arr;

int bfs(int y, int x) {
	struct node {
		int y, x, lv;
	};

	int direct[4][2] = {
		-1,0,
		0,-1,
		1,0,
		0,1
	};

	int head = 0;
	int tail = 0;
	node queue[1000];
	queue[tail++] = { y,x,0 };

	while (head != tail) {
		node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= 5 || dx >= 5) continue;
			if (vect[dy][dx] == -1) continue;
			if (visit[dy][dx] == 1) continue;
			visit[dy][dx] = 1;

			queue[tail++] = { dy,dx,now.lv + 1 };

			if (vect[dy][dx] == 1) {
				arr.push_back({dy,dx,now.lv + 1});
				return 1;
			}
		}
	}

	return 0;
}

bool compare(fish a, fish b) {
	if (a.move < b.move) return true;
	if (a.move > b.move) return false;
	if (a.move == b.move) {
		if (a.y < b.y) return true;
		if (a.y > b.y) return false;
		if (a.y == b.y) {
			if (a.x < b.x) return true;
			if (a.x > b.x) return false;
		}
	}
	return false;
}

int main() {
	int y, x;
	
	cin >> y >> x;
	cin.ignore();
	for (int i = 0; i < 5; i++) {
		int a = 0, b = 0;
		string str, tmp;
		getline(cin, str);
		while (1) {
			b = str.find(' ', a);
			if (b == -1) {
				b = str.length();
				tmp = str.substr(a, b - a);
				vect[i].push_back(stoi(tmp));
				visit[i].push_back(0);
				break;
			}
			tmp = str.substr(a, b - a);
			vect[i].push_back(stoi(tmp));
			visit[i].push_back(0);
			a = b + 1;
		}
	}

	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < visit[i].size(); k++) {
				visit[i][k] = 0;
			}
		}

		for(int i = 0; i < arr.size(); i++) visit[arr[i].y][arr[i].x] = 1;

		int flag = bfs(y, x);
		if (flag == 0) break;
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].y << " " << arr[i].x << " " << arr[i].move << endl;
	}

	return 0;
}