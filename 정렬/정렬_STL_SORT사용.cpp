/*
복권 번호를 추천해주는 프로그램을 제작해야 합니다.

n을 입력받고, n x n 번호판과, n x n 비트배열을 입력받으세요. ( 1 <= n <= 10 )
비트배열 값이 '1' 인 좌표에 해당하는 번호판 숫자를 추출합니다.

만약 번호판이 아래와 같이 입력을 받고,
3 4 1 6
7 7 2 4
2 6 4 5
4 2 6 5

만약 비트배열이 아래와 같이 입력을 받는다면,
0 1 0 0
0 1 0 0
0 0 1 0
0 1 0 0

추출된 숫자는 4 7 4 2 입니다.
추출된 숫자를 아래 조건에 맞게 정렬 하면 됩니다.
추출 및 정렬이 완료된 숫자 Set를 알려주는 프로그램을 제작 해 주세요.

[정렬 우선 순위]
1. 빈도수가 높을 수록, 우선순위가 높다.
2. 숫자가 작을수록, 우선순위가 높다.

[입력]
4
3 4 1 6
7 7 2 4
2 6 4 5
4 2 6 5
0 1 0 0
0 1 0 0
0 0 1 0
0 1 0 0

[출력]
4 4 2 7
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dat[10];

bool compare(int a, int b) {
	if (dat[a] > dat[b]) return true;
	if (dat[a] < dat[b]) return false;

	return a < b;
}

int main() {
	vector<int> vect;
	int map[10][10];
	int bit;
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int k = 0; k < num; k++) {
			cin >> map[i][k];
		}
	}

	for (int i = 0; i < num; i++) {
		for (int k = 0; k < num; k++) {
			cin >> bit;

			if (bit == 1) {
				vect.push_back(map[i][k]);
				dat[map[i][k]]++;
			}
		}
	}

	sort(vect.begin(), vect.end(), compare);

	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}

	return 0;
}