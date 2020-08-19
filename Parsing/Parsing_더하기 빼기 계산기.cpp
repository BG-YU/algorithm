/*
'+' 와 '-' 기호가 들어있는 수식을 입력받고
자동으로 계산해주는 프로그램을 작성 해 주세요.

[세부조건]
1. 괄호는 없습니다.
2. 첫 번째 수는 양수 또는 음수가 될 수 있습니다.
3. + 와 - 이외 문자는 입력되지 않습니다.
4. 띄어쓰기 없이 입력이 됩니다.
5. 문자열 길이 최대값 : 1000
6. 최종 결과는 음수가 될 수 있습니다.
7. 첫번째 수가 양수라면 '+' 기호가 생략됩니다.


[입력 예제]
100+100-50+30

[출력 결과]
180
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> vect;

int fn_index(int index, string* sign) {
	for (int i = index; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (i == 0 && str[i] == '-') continue;
			*sign = str[i];
			return i;
		}
	}
	return -1;
}

int main() {
	int sum = 0;
	string sign;
	cin >> str;
	int index = 0;
	while (1) {
		int ret = fn_index(index, &sign);
		if (ret == -1){
			ret = str.length();
			string tmp = str.substr(index, ret - index);
			vect.push_back(tmp);
			break;
		}
		string tmp = str.substr(index, ret - index);
		
		vect.push_back(tmp);
		vect.push_back(sign);

		index = ret + 1;
	}

	for (int i = 0; i < vect.size(); i++) {
		if (i == 0) {
			sum += stoi(vect[i]);
			continue;
		}
		if (vect[i] == "+" || vect[i] == "-") continue;
		
		if (vect[i - 1] == "+") sum += stoi(vect[i]);
		else sum -= stoi(vect[i]);
	}

	cout << sum;

	return 0;
}