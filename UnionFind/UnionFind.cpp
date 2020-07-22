/*
UnionFind

노드 4개의 연결상태를 입력 받으세요.
Cycle이 있는 그래프인지 아닌지 판별하면 됩니다.
Cycle을 확인 후 발견 또는 미발견을 출력 해주세요.

만약, 다음과 같은 그래프를 입력 받았다면 Cycle이 있으므로 "발견"을 출력하면 됩니다.

a<->b
a<->c
b<->c
b<->d
*/

#include <iostream>
using namespace std;

int arr[100];

char findboss(char ch) {
	if (arr[ch] == 0) return ch;
	return findboss(arr[ch]);
}

int setunion(char a, char b) {
	char aa = findboss(a);
	char bb = findboss(b);

	if (aa == bb) return 1;
	arr[b] = a;

	return 0;
}

int main() {
	int num, ret;
	char a, b;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		ret = setunion(a, b);
	}

	if (ret == 1) cout << "발견";
	else cout << "미발견";

	return 0;
}