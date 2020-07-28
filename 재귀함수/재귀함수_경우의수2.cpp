/*
카드 4장을 뽑아 3000을 초과 하는 카드를 만들수 있는 경우의수는 몇가지 인가?

입력 예제
2 5 1 6

출력 결과
12
*/
#include <iostream>
#include <string>
using namespace std;

char arr[4];
char path[4];
int used[4];
string temp;
int cnt;

void run(int lv) {
	if (lv >= 4) {
		for (int i = 0; i < 4; i++) {
			temp += path[i];
		}

		if (stoi(temp) > 3000) cnt++;
		temp = "";
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i] == 1) continue;
		path[lv] = arr[i];
		used[i] = 1;
		run(lv + 1);
		path[lv] = 0;
		used[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 4; i++) cin >> arr[i];

	run(0);

	cout << cnt;

	return 0;
}