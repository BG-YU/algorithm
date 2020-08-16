/*
입력받은 문자를 Split를 하여 target값을 만들수 있는지의 여부

입력문자 : ATS|AK|C|AS|TY
SPLIT 문자 : |
target 문자 : ASATS
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str = "ATS|AK|C|AS|TY";
string target = "ASATS";
vector<string> vect;
vector<int> used;

int flag = 0;

void dfs(string tmp) {
	if (tmp.length() > target.length()) {
		flag = 0;
		return;
	}

	if (tmp == target) {
		flag = 1;
		return;
	}

	for (int i = 0; i < vect.size(); i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(tmp + vect[i]);
		used[i] = 0;
		if (flag == 1) return;
	}
}

int main() {
	int a = 0;
	int b = 0;
	while (1) {
		b = str.find('|', a);
		if (b == -1) {
			b = str.length();
			string tmp = str.substr(a, b - a);
			vect.push_back(tmp);
			used.push_back(0);
			break;
		}

		string tmp = str.substr(a, b - a);
		vect.push_back(tmp);
		used.push_back(0);
		a = b + 1;
	}

	dfs("");

	if (flag == 1) cout << "가능";
	else cout << "불가능";

	return 0;
}
