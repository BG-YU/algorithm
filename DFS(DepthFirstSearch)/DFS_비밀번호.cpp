/*
A ~ Z 까지 대입을 해봐서 암호를 알아내려고 합니다.
아래의 순서대로 대입을 해보려합니다.
AAAA
AAAB
AAAC
  ...
ZZZZ
자전거 암호 n개가 존재할때, 몇회만에 각 암호를 해제 할 수 있는지 출력하세요.

ex)
[입력]
3 (자건거 암호 개수)
AAAC (암호 입력)
ATKC (암호 입력)
ZBAB (암호 입력)

[출력]
3
13107
440078
*/
#include <iostream>
#include <cstring>
using namespace std;

char pwd[10][5];
char path[4];
int used[10];
int num;
int cnt = 0;

int isSame(char temp[5]) {
	for (int i = 0; i < 4; i++) {
		if (temp[i] != path[i]) return 1;
	}
	return 0;
}

void run(int level) {
	if (level == 4) {
		cnt++;
		for (int i = 0; i < num; i++) {
			int ret = isSame(pwd[i]);
			if (ret == 0) cout << cnt << endl;
		}
		return;
	}

	for (char i = 'A'; i <= 'Z'; i++) {
		path[level] = i;
		run(level + 1);
		path[level] = 0;
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) cin >> pwd[i];
	run(0);
	return 0;
}