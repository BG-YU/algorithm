/*
[] 괄호안의 문자만 출력
*/
#include <iostream>
using namespace std;

int main() {
	string str = "ABC[OP]MBKFH[4F]ADFKH[ZZ]";
	int cnt = 0;

	while (1) {
		int index1 = str.find('[', cnt);
		if (index1 == -1) break;
		int index2 = str.find(']', index1 + 1);
		if (index2 == -1) break;

		string tmp = str.substr(index1 + 1, index2 - index1 - 1);
		cout << tmp << endl;
		cnt = index2 + 1;
	}

	return 0;
}