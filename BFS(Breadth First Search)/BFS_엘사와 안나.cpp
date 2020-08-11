/*
빙하 왕국의 엘사와 안나가 빙하 평원에서 길을 잃었습니다.
빙하를 피해 엘사와 안나가 가장 빠르게 만날 수 있는 이동시간을 계산해주세요.

엘사와 안나는 1초 마다 네 방향으로 각각 상, 하, 좌, 우로 움직일 수 있습니다.
또한, 엘사와 안나는 제자리에 멈춰있는 것도 가능합니다.

빙하 평원에서 빙하가 있는 위치로는 안나와 엘사가 이동할 수 없습니다.
빙하의 위치는 아래 그림과 같습니다.

엘 : 엘사
안 : 안나
■ : 빙하
□ : 평원

엘□□■□
□□□■□
■■□□□
□□■□□
안□□□□


[입력]
엘사의 위치 y, x 가 입력 된 후에, 안나의 위치 y, x 가 입력 됩니다.

[출력]
두 사람이 같은 위치에서 만나게 될 때, 가장 최소 이동시간을 출력 해주세요.

[입력 예제]
0 0
4 0

[출력 결과]
5
*/
#include <iostream>
using namespace std;

int main() {
	struct node {
		int y1, x1, y2, x2, lv;
	};
	int map[5][5] = {
		0,0,0,1,0,
		0,0,0,1,0,
		1,1,0,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	};
	
	int direct[4][2] = {
		-1,0,
		0,-1,
		1,0,
		0,1
	};
	int visit1[5][5] = { 0 };
	int visit2[5][5] = { 0 };
	int head = 0;
	int tail = 0;
	int flag = 0;
	int n1, n2, n3, n4;

	cin >> n1 >> n2 >> n3 >> n4;
	visit1[n1][n2] = 1;
	visit2[n3][n4] = 1;
	node queue[1000];
	queue[tail++] = { n1,n2,n3,n4,0 };

	while (head != tail) {
		node now = queue[head++];

		for (int i = 0; i < 4; i++) {
			flag = 0;
			int dy1 = direct[i][0] + now.y1;
			int dx1 = direct[i][1] + now.x1;
			int dy2 = direct[i][0] + now.y2;
			int dx2 = direct[i][1] + now.x2;

			if ((dy1 < 0 || dx1 < 0 || dy1 > 4 || dx1 > 4) && (dy2 < 0 || dx2 < 0 || dy2 > 4 || dx2 > 4)) continue;
			
			node tmp = { now.y1, now.x1, now.y2, now.x2, now.lv + 1 };

			if (!(dy1 < 0 || dx1 < 0 || dy1 > 4 || dx1 > 4)) {
				if (map[dy1][dx1] != 1 && visit1[dy1][dx1] != 1) {
					flag = 1;
					visit1[dy1][dx1] = 1;
					queue[tail] = {dy1, dx1, tmp.y2, tmp.x2, tmp.lv};
					tmp = queue[tail];
				}
			}

			if (!(dy2 < 0 || dx2 < 0 || dy2 > 4 || dx2 > 4)) {
				if (map[dy2][dx2] != 1 && visit2[dy2][dx2] != 1) {
					flag = 1;
					visit2[dy2][dx2] = 1;
					queue[tail] = { tmp.y1, tmp.x1, dy2, dx2, tmp.lv };
				}
			}

			for(int i = 0; i < 5; i++){
				for (int k = 0; k < 5; k++) {

					if (visit1[i][k] == visit2[i][k] && visit1[i][k] == 1 && visit2[i][k] == 1) {
						cout << now.lv + 1;
						return 0;
					}
				}
			}
			if(flag == 1) tail += 1;
		}
	}
	return 0;
}