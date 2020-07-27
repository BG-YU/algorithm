/*
항의 갯수를 입력 받고 입력받은 항의 갯수로 10을 만들수 있는 경우의 수는 몇가지 인가?

[입력]
3
[출력]
36
*/
#include <iostream>
using namespace std;

int num;
int cnt;

void run(int lv, int sum) {
	
	if (lv == num) {
		if (sum == 10) cnt++;
		return;
	}

	for (int i = 1; i < 10; i++) {
		run(lv + 1, sum + i);
	}
}

int main() {
	cin >> num;

	run(0, 0);

	cout << cnt;
	return 0;
}