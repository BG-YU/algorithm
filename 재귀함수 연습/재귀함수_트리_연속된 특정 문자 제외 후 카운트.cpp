/*
[문제]
네 글자를 입력 받으세요.

네 글자를 조합하여 나올수 있는 모든 경우가 몇가지인지 알아내고자 합니다.

그런데 B와 T 글자는 서로 붙어있으면 안됩니다.

재귀호출을 이용해서 풀어주세요
 

ex)

만약, BOTK 네글자를 입력받았다면,

BBBB   -> 가능

BBBT   -> 불가능

BOOT  -> 가능

TTBK   -> 불가능

TTTK   -> 가능


네 글자를 입력받고,

B와 T글자가 서로 붙어있지 않은 총 경우의 수가 몇 가지인지 출력하세요.

[입력 예제]
BOTT

[출력 결과]
120
*/
#include <iostream>
using namespace std;

char temp[5], path[4];
int cnt=0;
void run(int level){
	if(level == 4) {
		cnt++;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		if(level > 0 && ((path[level - 1] == 'B' && temp[i] == 'T') || (path[level - 1] == 'T' && temp[i] == 'B'))) continue;
		path[level] = temp[i];
		run(level + 1);
		path[level] = 0;
	}
	
	return;
}

int main() {
	cin >> temp;
	run(0);
	cout << cnt;
	return 0;
}