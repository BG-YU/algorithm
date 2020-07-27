/*
다음 MAP행렬에서 최소비용과 경로를 출력

[입력]
시작점고 도착지점을 입력 받으세요.

[출력]
최소 비용과 경로를 출력해주세요.
갈 수 있는 길이 없다면 "impossible" 을 출력 하세요.
*/

#include <iostream>
using namespace std;

int map[5][5] = {
	0,3,6,2,0,
	0,0,2,0,4,
	0,0,0,0,1,
	0,0,0,0,8,
	0,10,0,0,0
};
char name[5] = { 'G','T','H','K','B' };
char path[10];
char temp[10];
int used[5];
int sum = 0;
int minn = 21e8;
int flag = 0;
int cnt = 0;

void  dfs(int lv, char end, int index) {
	if (name[index] == end) {
		if (minn > sum) {
			minn = sum;
			for (int i = 0; i < 10; i++) temp[i] = path[i];
		}

		flag = 1;
		return;
	};

	for (int i = 0; i < 5; i++) {
		if (map[index][i] == 0 || used[i] == 1) continue;
		sum += map[index][i];
		used[i] = 1;
		path[lv + 1] = name[i];
		dfs(lv + 1, end, i);
		sum -= map[index][i];
		used[i] = 0;
		path[lv + 1] = 0;
	}

	return;
}

int main() {
	char c1, c2;

	cin >> c1 >> c2;

	for (int i = 0; i < 5; i++) {
		if (name[i] == c1) {
			used[i] = 1;
			path[0] = name[i];
			dfs(0, c2, i);
			if (flag == 1) cout << minn << ":" << temp;
			else cout << "impossible";
			break;
		}
	}

	return 0;
}