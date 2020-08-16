/*
무작위로 3군데를 잘랐을때의 계산의 MAX값은?

ex)
입력받은 숫자 : 4785169
3군데 잘랐을때 : 47/85/16/9
계산식 : (((47 + 85) * 16) / 9)
*/

#include <iostream>
#include <string>
using namespace std;

string str = "4785169";

int fn_split(int index1, int index2, int index3) {
	string tmp1 = str.substr(0, index1 + 1);
	string tmp2 = str.substr(index1 + 1, index2 - index1);
	string tmp3 = str.substr(index2 + 1, index3 - index2);
	string tmp4 = str.substr(index3 + 1, str.length() - 1);

	return (((stoi(tmp1) + stoi(tmp2)) * stoi(tmp3)) / stoi(tmp4));
}


int main() {
	int maxx = -21e8;
	for (int i = 0; i < str.length() - 3; i++) {
		for (int k = i + 1; k < str.length() - 2; k++) {
			for (int j = k + 1; j < str.length() - 1; j++) {
				int ret = fn_split(i, k, j);
				if (maxx < ret) maxx = ret;
			}
		}
	}

	cout << maxx;

	return 0;
}