/*
하나의 문자열에 여러 e-mail 주소가 저장되어 있습니다.
각 e-mail은 '|' bar를 구분기호로 나누어져 있습니다.

메일 주소는
[이름] @ [도메인이름] [최상위도메인] 형태로 구성되어 있습니다.

각 e-mail 주소에서 [이름] 과 [도메인이름]만 추출 해 주세요.
그리고 추출된 문자열을 정리하여 다음과 같은 Format으로 출력 해 주세요.

[#이름] 도메인이름


[세부사항]
1. 잘못된 e-mail 형식은 입력받지 않습니다.
2. .co.kr .com 외 다양한 최상위도메인이 입력으로 주어질 수 있습니다.

[입력 예제]
bbq@mcdonald.co.kr|jyp@sam.com|imac@donald.com

[출력 결과]
[#bbq] mcdonald
[#jyp] sam
[#imac] donald
*/
#include <iostream>
#include <string>
using namespace std;

string fn_split(string tmp) {
	string str = "[#";
	int a = tmp.find("@", 0);
	str += tmp.substr(0, a);
	str += "] ";
	str += tmp.substr(a + 1, tmp.find(".", a + 1) - (a + 1));
	return str;
}

int main() {
	string str;
	cin >> str;
	int a = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '|') {
			int t = str.find("|", i + 1);
			string tmp = str.substr(a, i - a);
			cout << fn_split(tmp) << endl;
			a = i + 1;
			if (t == -1) {
				tmp = str.substr(i + 1, str.length() - (i + 1));
				cout << fn_split(tmp) << endl;
				break;
			}
		}
	}

	return 0;
}
