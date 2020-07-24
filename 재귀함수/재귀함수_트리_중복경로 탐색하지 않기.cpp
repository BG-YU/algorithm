/*
[문제]
네 명의 친구들의 이름을 입력 받아 주세요. (사람당 한글자씩, 총 4글자)
그리고 이 친구들 중 1등, 2등, 3등을 뽑아 선물을 주려고 합니다.
한 사람은 하나의 선물만 받을 수 있습니다.
선물을 줄 수 있는 경우를 모두 출력 해주세요.


[입력]
ATKP

[출력]
ATK
ATP
AKT
AKP
APT
APK
TAK
TAP
TKA
TKP
TPA
TPK
KAT
KAP
KTA
KTP
KPA
KPT
PAT
PAK
PTA
PTK
PKA
PKT
*/
#include <iostream>
using namespace std;

char path[4], used[4], temp[5];

void run(int level){
	if(level == 3){
		cout << path << endl;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		if(level > 0 && used[i] == temp[i]) continue;
		path[level] = temp[i];
		used[i] = temp[i];
		run(level + 1);
		path[level] = 0;
		used[i] = 0;
	}
	
	return;
}

int main() {
	cin >> temp;
	run(0);
	return 0;
}