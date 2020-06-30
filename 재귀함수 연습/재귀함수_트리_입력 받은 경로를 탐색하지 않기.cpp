/*
[문제]
'E', 'W', 'A', 'B', 'C' 라는 친구들이 놀이기구를 타려고 합니다.
이 놀이기구는 가장 앞좌석부터 뒷좌석까지 4명이 탈 수 있는 보트입니다.
다섯명의 친구들 중 탈 순서를 정해야 하는데,
한명을 제외시켜야 합니다.
제외시킬 친구를 입력받고 (문자 1개입력)
이 친구를 제외한 모든 순열을 출력 해 주세요.

[입력 예제]
E

[출력 결과]
WABC
WACB
WBAC
WBCA
WCAB
WCBA
AWBC
AWCB
ABWC
ABCW
ACWB
ACBW
BWAC
BWCA
BAWC
BACW
BCWA
BCAW
CWAB
CWBA
CAWB
CABW
CBWA
CBAW
*/
#include <iostream>
using namespace std;

char chr;
char temp[5] = { 'E','W','A','B','C' };
char path[5], used[5];


void run(int lv) {
	if (lv == 4) {
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (temp[i] == chr) continue;
		if (used[i] == temp[i]) continue;
		path[lv] = temp[i];
		used[i] = temp[i];
		run(lv + 1);
		path[lv] = 0;
		used[i] = 0;

	}
}

int main() {
	cin >> chr;
	run(0);
	return 0;
}