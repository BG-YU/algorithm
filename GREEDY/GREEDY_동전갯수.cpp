/*
입력받은 거슴름돈을 돌려 줄대 최소의 동전 갯수는?

동전
500 100 50 10
*/

#include <iostream>
using namespace std;

int main() {
	int num, cnt = 0;
	cin >> num;
	while (1) {
		if (num == 0) break;
		else if (num >= 500) num -= 500;
		else if (num >= 100) num -= 100;
		else if (num >= 50) num -= 50;
		else if (num >= 10) num -= 10;
		cnt++;
	}

	cout << cnt;
	return 0;
}