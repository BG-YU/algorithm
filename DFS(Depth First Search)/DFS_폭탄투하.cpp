/*
적군이 깔려있는 맵에 폭탄을 떨어뜨리려고 합니다.
적군을 없애기 위해 폭탄 3개를 최대한 적합한 곳에 터트리고자 합니다.
폭탄을 (2,2)에 투하하면 폭발 범위가 아래처럼 총 5칸에서 폭발합니다.

□□□□
□□■□
□■■■
□□■□

4x4 맵에 알파벳 적군들이 포진해 있습니다.
어느 곳에 폭탄을 두어야 적군에게 가장 큰 피해를 줄 수 있을지 알려주는 프로그램을 작성 해 주세요.

[세부조건]
1. 폭탄은 알파벳이 있는 좌표에만 떨어뜨릴 수 있습니다.
2. 출력할 적의 이니셜은 사전식 순서로 출력 해 주세요.

[입력]
적군이 위치한 맵의 정보를 입력 받습니다.
적은 알파벳으로 입력되고, 빈 공간은 _ 로 입력 됩니다.

[출력]
사전순으로 떨어뜨릴 위치의 적군 알파벳을 출력 해주세요.

[입력 예제]
AB__
C___
G__D
HIFE

[출력 결과]
A E H
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char map[4][4];
char path[3], temp[3];
int maxx = -21e8;

int direct[5][2] = {
	-1,0,
	0,-1,
	1,0,
	0,1,
	0,0
};

void fn_direct(int y, int x) {
	for (int i = 0; i < 5; i++) {
		int dy = direct[i][0] + y;
		int dx = direct[i][1] + x;

		if (dy < 0 || dx < 0 || dy > 3 || dx > 3) continue;
		if (map[dy][dx] == '_') continue;
		map[dy][dx] = '0';
	}
}

int fn_calc() {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (map[i][k] == '0') cnt++;
		}
	}
	return cnt;
}

void dfs(int lv) {
	char back[4][4];

	if(lv == 3){
		int ret = fn_calc();
		if (maxx < ret) {
			maxx = ret;
			memcpy(temp, path, 1 * 4 * 4);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (map[i][k] == '_' || map[i][k] == '0') continue;
			else {
				memcpy(back, map, 1 * 4 * 4);
				path[lv] = map[i][k];
				fn_direct(i, k);
				dfs(lv + 1);
				memcpy(map, back, 1 * 4 * 4);
				path[lv] = '\0';
			}
		}
	}

	return;
}


int main() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			cin >> map[i][k];
		}
	}

	dfs(0);
	sort(temp, temp + 3);

	for (int i = 0; i < 3; i++) cout << temp[i] << " ";
	return 0;
}