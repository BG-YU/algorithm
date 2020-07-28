/*
문자 메세지에 다이어트에 도움이 안 되는 단어가 있으면, 모두 3개의 #으로 (###) 모자이크 처리하려고 합니다.
성공적인 다이어트를 위해, 문자메세지 필터기능을 완성시켜주세요.

모자이크 처리 할 5개의 위험 단어들은 다음과 같습니다.
대소문자 구분 없이 위험 단어가 있으면 모자이크 처리 해 주세요.

"chicken"
"pizza"
"jockbal"
"bread"
"samhap"


입력 예제
HeyBread!DoYouWannaBuildAChicken

출력 결과
Hey###!DoYouWannaBuildA###
*/

#include <iostream>
#include <string>
using namespace std;

string str, temp;
int flag;
char chr;
string no[5] = {
	"chicken",
	"pizza",
	"jockbal",
	"bread",
	"samhap"
};

int fn_chk(int index) {
	if (index >= str.length()) return 0;
	int len = 0;
	for(int i = 0; i < 5; i++){
		for(int k = 0; k < no[i].length(); k++){
			chr = str[k + index];

			if (!(chr >= 'a' && chr <= 'z')) chr = chr + ('a' - 'A');

			if (chr != no[i][k]) {
				flag = 0;
				break;
			}
			else flag = 1;
		}
		if(flag == 1){
			len = no[i].length();
			flag = 0;
		}
	}

	return len;
}

void run(int lv) {
	if (lv >= str.length()) return;
	int ret = fn_chk(lv);
	if (ret > 0) {
		for (int i = 0; i < 3; i++) temp += "#";
		run(lv + ret);
	}
	else {
		temp += str[lv];
		run(lv + 1);
	}
}

int main() {
	cin >> str;

	run(0);

	cout << temp;
	return 0;
}