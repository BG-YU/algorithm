/*
디아블로가 봉인된 퍼즐이 있습니다. 이 퍼즐을 풀면 디어블로가 깨어납니다.
아래와 같이 Z 기준으로 한번 돌리면 Z를 둘러싸고 있는 문자들이 회전합니다.

AAA     CBA
BZB --> CZA 
CCC     CBA

가로로 AAA가 맞춰지면 퍼즐이 맞춰진 것 입니다.
퍼즐 상태를 입력받고 6회 안에 (6회 포함) 퍼즐을 풀 수 있는지 출력 해주세요.

[입력]
퍼즐의 정보를 입력 받습니다.

[출력]
6회 이하로 퍼즐을 맞출 수 있으면 가능, 아니면 불가능 이라고 출력 해주세요.

[예시]
아래 예제에서는 좌표 (1,1), (1,2), (2,1), (2,2) 까지 선택 할 수 있고, 선택하면 퍼즐이 시계방향으로 돌아갑니다.
ABTB
ATCD
BGAD
ABCT

[입력 예제]
ABTB
ATCD
BGAD
ABCT

[출력 결과]
가능
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> vect;
int flag = 0;

void spin(int y, int x) {
	int dy = y - 1;
	int dx = x - 1;
	vector<string> temp(vect.size());
	copy(vect.begin(), vect.end(), temp.begin());

	for (int i = dy; i < vect.size(); i++) {
		for (int k = dx; k < vect[i].length(); k++) {
			temp[k][vect.size() - i] = vect[i][k];
		}
	}
	copy(temp.begin(), temp.end(), vect.begin());
	return;
}

int calc(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (vect[i][k] == 'A') cnt++;
			if (cnt >= 3) return 1;
		}
		cnt = 0;
	}
	return 0;
}

void dfs(int lv) {
	vector<string> temp(vect.size());

	int ret = calc(vect.size());
	if (ret == 1) {
		flag = 1;
		return;
	}

	if (lv == 6) return;

	for (int i = 0; i < vect.size(); i++) {
		for (int k = 0; k < vect[i].length(); k++) {
			if (i == 0 || i == vect.size() - 1 || k == 0 || k == vect[i].length() - 1) continue;
			copy(vect.begin(), vect.end(), temp.begin());
			spin(i, k);
			dfs(lv + 1);
			copy(temp.begin(), temp.end(), vect.begin());
		}
	}

	return;
}

int main() {
	string temp;
	int cnt = 0;

	while (1) {
		getline(cin, temp);
		vect.push_back(temp);
		cnt++;
		if (vect[0].length() == cnt) break;
	}
	dfs(0);

	if (flag == 1) cout << "가능";
	else cout << "불가능";

	return 0;
}