/*
가장 긴 장어길이 구하기

[입력]
#~~~~~~~#~~~~#

[출력]
~~~~~~~
*/
#include <iostream>
#include <string>
using namespace std;

int cnt, maxx = -21e8;
string str;

void run(int lv) {
	if (str[lv] == '#') {
		if (maxx < cnt) {
			maxx = cnt;
			cnt = 0;
		}
	}
	else cnt++;

	if (lv == str.length() - 1) return;

	run(lv + 1);
}

int main() {
	
	cin >> str;
	
	run(0);

	for (int i = 0; i < maxx; i++) cout << "~";

	return 0;
}