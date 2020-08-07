/*
시어머니와 며느리는 명절을 맞아 고기를 굽고 있습니다.
고기를 뒤집어 모든 같은 방향이 나올때, 가장 적은 뒤집기 횟수를 구해주세요.
고기의 상태를 입력 받습니다. O는 앞면, X는 뒷면 입니다.
시어머니가 고기를 뒤집을 곳을 지목합니다.
며느리는 시어머니가 지목한 곳과 양쪽 좌우를 모두 뒤집습니다.
아래 예제는 총 두번만에 고기를 모두 같은 방향으로 고기를 뒤집을 수 있습니다.

예제)
시어머니가 선택한 곳 : 2번 index
OXOOX -> OOXXX

[입력]
고기의 방향이 입력 됩니다.
O는 앞면, X는 뒷면으로 두 종류의 입력으로 구성되어 있습니다.

[출력]
모두 같은 방향 (전체 OOOO... 또는 전체 XXXX...) 으로 나오도록 고기를 뒤집을때 가장 적게 뒤집은 수를 출력해주세요.
만약 4회 만에 뒤집는 것을 실패한다면 impossible 이라고 출력 해 주세요.

[세부조건]
고기의 개수는 최대 20개 까지 될 수 있습니다.

[입력 예제]
OXOOX

[출력 결과]
2
*/

#include <iostream>
#include <cstring>
using namespace std;

int n = 0;
char meat[20];
int spin[3] = { -1,0,1 };
int flag = 0;
int minn = 21e8;

void fn_spin(int index) {
	for (int i = 0; i < 3; i++) {
		int dd = spin[i] + index;
		if (dd < 0 || dd > n - 1) continue;
		if (meat[dd] == 'O') meat[dd] = 'X';
		else meat[dd] = 'O';
	}
	return;
}

int fn_equal() {
	for (int i = 0; i < n - 1; i++) {
		if (meat[i] != meat[i + 1]) return 0;
	}
	return 1;
}

void dfs(int lv) {
	char temp[20];

	int ret = fn_equal();

	if (ret == 1) {
		if (minn > lv) minn = lv;
		flag = 1;
	};

	if (lv == 4) return;

	for (int i = 0; i < n; i++) {
		memcpy(temp, meat, sizeof(char) * 20);
		fn_spin(i);
		dfs(lv + 1);
		memcpy(meat, temp, sizeof(char) * 20);
	}

	return;
}

int main() {
	cin.getline(meat, 20);
	for (int i = 0; i < 20; i++) {
		if (meat[i] == '\0') {
			n = i;
			break;
		}
	}

	dfs(0);

	if (flag == 1) cout << minn;
	else cout << "impossible";
	return 0;
}