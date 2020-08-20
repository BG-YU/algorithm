/*
_(언더바)를 제외한 모든 단어들을 배열에 저장하고자 합니다.
각 칸에 '_'를 기준으로 단어들을 string 배열에 parsing 해주세요.

[입력 예제]
HOT_FRIED____CHICKEN_KFC_IS_BEST

[출력 결과]
1#HOT
2#FRIED
3#CHICKEN
4#KFC
5#IS
6#BEST
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, tmp;
	int cnt = 1;
	cin >> str;

	// 문자열 뒷부분에 언더바가 없을 경우 하나 추가
	if (str[str.length() - 1] != '_') str.insert(str.length(), "_");

	// 문자열 앞 언더바 전부 제거
	for (int i = 0; i < str.length(); i++) {
		if (str[0] == '_') str.erase(0, 1);
		else break;
	}

	for (int i = 0; i < str.length(); i++) {
		// 문자열 중간에 언더바가 중복으로 있을 경우 
		// 일관된 규칙성을 위해 언더바 하나만 남기고 전부 제거
		if (str[i] == '_' && str[i - 1] == '_') {
			str.erase(i, 1);
			i--;
			continue;
		}

		// parsing
		if (str[i] == '_') {
			cout << cnt++ << "#" << tmp << endl;
			tmp = "";
			continue;
		}

		tmp += str[i];
	}

	return 0;
}
