/*
암호를 사용하여 문자의 순서를 바꾼다.

암호 : 523164

EX)
1. AEWFGB의 문장에서 5번째 문자인 G를 첫번째
2. AEWFGB의 문장에서 2번째 문자인 E를 두번째
3. AEWFGB의 문장에서 3번째 문자인 W를 세번째
4. AEWFGB의 문장에서 1번째 문자인 A를 네번째
5. AEWFGB의 문장에서 6번째 문자인 B를 다섯번째
6. AEWFGB의 문장에서 4번째 문자인 F를 여섯번째

AEWFGB
523164
  ↓
GEWABF

위 1~6의 과정을 거쳐 완성된 문자는 GEWABF이다.
AEWFGBAFDW문자를 변환하여 완성된 문자를 출력하라.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int pw[6] = { 5,2,3,1,6,4 };
	int cnt = 0;
	string str1, str2;
	str1 = "AEWFGBAFDW";
	str2 = str1;

	for (int i = 0; i <= str1.length() - 6; i++) {
		for (int k = i; k < i + 6; k++) {
			str2.erase(k, 1);
			string tmp = "";
			int n = (pw[cnt++] - 1) + i;
			tmp += str1[n];
			str2.insert(k, tmp);
			tmp = "";
		}
		str1 = str2;
		cnt = 0;
	};

	cout << str2;

	return 0;
}