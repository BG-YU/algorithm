/*
T,K,A,B 4사람이 3자리만 있는 놀이기구를 탈려고 한다.
3자리로 구성할수 있는 조합을 출력하시오
*/

#include <iostream>
using namespace std;

char arr[5] = { "TKAB" };
char path[3];

void run(int lv, int start) {

	if (lv == 3) {
		cout << path << endl;
		return;
	}

	for (int i = start; i < 4; i++) {
		path[lv] = arr[i];
		run(lv + 1, i + 1);
		path[lv] = 0;
	}
}

int main() {
	run(0, 0);
	return 0;
}