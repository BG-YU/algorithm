/*
n개 도시의 여행경로 그래프(인접행렬)를 입력받아주세요.
이 중에 값 비싼 항로 Top 3개만 판매를 하려고 합니다.

간선의 길이와 정보들을 모두 Heap에 넣어두고 (구조체 Heap)
가장 비싼 간선 3개를 뽑아 출력 해 주세요.

=============
  A  B  C  D
A 0  0  30 20
B 10 0  5  40
C 10 0  0  5
D 0  50 0  0
=============

입력 예제
4
0 0 30 20
10 0 5 40
10 0 0 5
0 50 0 0

출력 결과
D-B 50
B-D 40
A-C 30
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
	string route;
	int value;
};

priority_queue<node, vector<node>> pq;

bool operator<(node a, node b) {
	if (b.value > a.value) return true;
	if (b.value < a.value) return false;

	return a.route < b.route;
}

int main() {
	int map[10][10];
	int cnt = 0;
	node route;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		for (int k = 0; k < cnt; k++) {
			cin >> map[i][k];
		}
	}

	for (int i = 0; i < cnt; i++) {
		for (int k = 0; k < cnt; k++) {
			if (map[i][k] == 0) continue;
			route.route += i + 'A';
			route.route += '-';
			route.route += k + 'A';
			route.value = map[i][k];
			pq.push(route);
			route.route = "";
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << pq.top().route << " " << pq.top().value << endl;
		pq.pop();
	}

	return 0;
}