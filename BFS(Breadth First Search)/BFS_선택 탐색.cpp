/*
터미네이터의 신경체계가 다음과 같이 트리형태로 되어있다고 합니다.
인접행렬 형태로 초기화를 해 주세요.
이 신경쳬계를 트리로 하드코딩 하고, 나노 탐사로봇이 탐색을 하려고 합니다.
BFS 알고리즘을 쓸때 탐사순서대로 출력해주세요.
예를들어 E를 입력받았다면,
E에서 출발하는 BFS를 돌리면 됩니다. (출력결과 : E H J)

[터미네이터 신경계]
     A
    ↓ 
     B
↙ ↓ ↓ ↘
C  D  E   F
   ↓ ↓
   G  H
   ↓ ↓
   I  J

예를들어 B를 입력받았다면,
B에서 출발하는 BFS를 돌리면 됩니다. (출력결과 : B C D E F G H I J)

[입력 예제]
A

[출력 결과]
A B C D E F G H I J
*/
#include <iostream>
using namespace std;

char name[10] = {'A','B','C','D','E','F','G','H','I','J'};
int map[10][10] = {
	0,1,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,0,
	0,0,0,0,0,0,0,0,0,1
};

int main() {
	char chr;
	int cnt;
	cin >> chr;
	
	for (int i = 0; i < 10; i++) {
		if (name[i] == chr) cnt = i;
	}

	struct node {
		int num;
		int level;
	};

	node queue[30] = { 0 };

	int head = 0;
	int tail = 1;
	
	queue[0].num = cnt;

	while (head != tail) {
		node now = queue[head++];
		
		cout << name[now.num] << " ";

		for (int i = 0; i < 10; i++) {
			if (map[now.num][i] == 0) continue;

			queue[tail++] = { i, now.level + 1 };
		}
	}

	return 0;
}