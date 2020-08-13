/*
5칸의 입구와 2개의 미닫이 문 (A, B)가 있습니다.
손님이 입장하는 번호 칸에 미닫이 문이 없어야 입장이 가능합니다.

예로들면 현재 미닫이문은 1번과 3번에 위치하기 때문에, 손님들은 지금 1번과 3번으로 입장할 수 없습니다.
미닫이 문A를 왼쪽 or 오른쪽으로 밀면, 손님은 1번으로 입장이 가능합니다.

예약고객들이 입장하는 순서는 정해져있습니다.
빠른 고객입장을 위해, 최소 횟수로 미닫이 문 A, B를 밀어야합니다.

[문을 이동하는 방법]
미닫이문의 초기 상태가 0 1 1 0 0 이고
고객이 1 2 0 순서대로 입장한다면 아래와 같이 미닫이문을 이동시킬 수 있습니다.

0 1 1 0 0

여기서 고객이 1번으로 들어 온다고 한다면 1번 칸에 있는 A문을 치워줘야 합니다.
(총 1회 문 이동)

1 0 1 0 0

만약 고객이 2번으로 들어 온다고 한다면 B문을 왼쪽 or 오른쪽으로 옮길 수 있습니다.
왼쪽으로 옮깁니다.
(총 2회 문 이동)

1 1 0 0 0

만약 고객이 0번으로 들어 온다면 A와 B를 각각 한 칸씩 밀어줘야 합니다.
(총 4회 문 이동)

0 1 1 0 0

이 예제에서는 총 4회 문을 이동 시켰습니다. 이 값은 최소 문 이동횟수는 아닙니다.
참고로, 위 예제에서 최소 이동횟수는 3회입니다.


[입력]
미닫이 문의 위치를 입력 받으세요.

[출력]
미닫이 문을 이동해야하는 최소 횟수를 출력 해주세요.

[예제]
손님 입장 순서 (하드코딩) : 0 1 0 1 0 1 2 3 2 3 2 3
문의 위치 입력 : 0 1 1 0 0

0 1 1 0 0 (시작) : 0 번째 손님 입장 완료
0 1 0 1 0 (총 1회 이동)
0 0 1 1 0 (총 2회 이동) : 1 ~ 5 번째 손님 입장 완료
0 0 1 0 1 (총 3회 이동)
0 1 0 0 1 (총 4회 이동) : 6 ~ 11 번째 손님 입장 완료
정답 : 4회


[입력 예제]
0 1 1 0 0

[출력 결과]
4
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int guest[12] = { 0,1,0,1,0,1,2,3,2,3,2,3 };
vector<int> vect;
struct node {
	int ab[2], guest,lv;
	vector<int> door;
};

int main() {
	int a = 1;
	string str;
	getline(cin, str);

	while (1) {
		int b = str.find(' ', a);
		vect.push_back(str[b - 1] - '0');
		a += 2;
		if (a >= str.length()) {
			vect.push_back(str[str.length() - 1] - '0');
			break;
		}
	}

	node queue[1000];
	int head = 0;
	int ab[2], cnt = 0;
	int tail = 0;
	int direct[3] = { -1,0,1 };

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] == 1) {
			ab[cnt++] = i;
		}
	}
	queue[tail++] = { {ab[0], ab[1]}, 0, 0, vect };

	while (head != tail) {
		node now = queue[head++];
		
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 3; k++) {
				node temp = now;
				int dx = now.ab[i] + direct[k];

				if (dx < 0 || dx >= temp.door.size()) continue;
				if (temp.door[dx] == 1) continue;
				while (1) {
					if (temp.guest > 11) break;
					if (temp.door[guest[temp.guest]] == 0) {
						temp.guest += 1;
					}
					else break;
				}
				if (direct[k] != 0) temp.lv += 1;
				temp.door[temp.ab[i]] = 0;
				temp.door[dx] = 1;
				temp.ab[i] = dx;

				queue[tail++] = temp;

				if (temp.guest > 11) {
					cout << temp.lv - 1;
					return 0;
				}
			}
		}
	}

	return 0;
}