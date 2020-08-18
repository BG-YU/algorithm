/*
독재자 알프레도는 국민들에게 금지어를 발표했습니다.
한 문자열을 입력받아주세요.
그리고 아래 표를 참조하여, 정책에 맞게 단어를 수정해주는 프로그램을 작성해주세요.

KFC    -> #BBQ#
MC     -> #BBQ#
BICMAC -> #MACBOOK#
SHACK  -> #SHOCK#
SONY   -> #NONY#

[입력 예제]
ILOVEKFCANDMC!!

[출력 결과]
ILOVE#BBQ#AND#BBQ#!!
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, string>> word;

void init() {
	word.push_back({ "KFC", "#BBQ#"});
	word.push_back({ "MC", "#BBQ#" });
	word.push_back({ "BICMAC", "#MACBOOK#" });
	word.push_back({ "SHACK", "#SHOCK#" });
	word.push_back({ "SONY", "#NONY#" });
}

int main() {
	init();
	string str;
	cin >> str;

	for (int i = 0; i < word.size(); i++) {
		int a = 0, b = 0;

		while (1) {
			b = str.find(word[i].first, a);
			if (b == -1) break;

			str.erase(b, word[i].first.length());
			str.insert(b, word[i].second);
			a = b + 1;
		}
	}

	cout << str;
	return 0;
}

