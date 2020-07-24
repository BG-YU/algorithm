/*
입력받은 문자중 대문자만 출력

[입력예제]
#MIn#C#O##dE

[출력결과]
MICEO
*/

#include <iostream>
#include <cstring>
using namespace std;

char arr[20];

void run(int now) {
	if (arr[now] == '#') return;
	if (now > strlen(arr)) return;
	if (arr[now] >= 'A' && arr[now] <= 'Z') {
		cout << arr[now];
	}

	run(now * 2);
	run(now * 2 + 1);
}

int main() {
	cin >> arr;

	run(1);

	return 0;
}