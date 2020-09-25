/*
공룡의 화석 8개가 발견되었습니다.
이 화석으로 공룡의 나이 조사 결과, 대부분 10억살 이상이었고 정확한 나이는 다음과 같습니다.

A공룡 : 1000000005살
B공룡 : 1000000006살
C공룡 : 1000000035살
D공룡 : 1000000002살
E공룡 : 1000000011살
F공룡 : 1000000005살
G공룡 : 1000000015살
H공룡 : 1000000025살


숫자를 입력 받고, 이 숫자와 같은 나이를 가진 공룡이 총 몇마리인지 출력 해주세요.

[힌트1]
숫자가 너무 커서 이 값을 배열의 index로 쓸 수 없기 때문에 Hash Function이 필요합니다.
그런데 Hash Function을 거치면 다른 값들이 같은 index에 들어갈 수 있기 때문에, Chaining이 필요합니다.

[힌트2]
HashTable(Bucket)에 담고, 내가 찾는 target값이 몇 개인지만 세면 됩니다.

[입력]
찾을 숫자를 입력 받으세요.

[출력]
몇마리가 해당 나이와 같은지 마리수를 출력 해주세요.
*/
#include <iostream>

using namespace std;

struct node {
	int age;
	node* next;
};

node buf[100]; //MemoryPool
node* head[5];
int cnt;


node* myalloc(int age, node* next) {
	buf[cnt] = { age, next };
	return &buf[cnt++];
}

void addnode(int from, int age) {
	head[from] = myalloc(age, head[from]);
}

int hashf(int age) {
	return age % 5;
}

int main() {
	addnode(hashf(1000000005), 1000000005);
	addnode(hashf(1000000006), 1000000006);
	addnode(hashf(1000000035), 1000000035);
	addnode(hashf(1000000002), 1000000002);
	addnode(hashf(1000000011), 1000000011);
	addnode(hashf(1000000005), 1000000005);
	addnode(hashf(1000000015), 1000000015);
	addnode(hashf(1000000025), 1000000025);
	int age, cnt = 0;;
	cin >> age;

	for (node* p = head[hashf(age)]; p != NULL; p = p->next) {
		if (p->age == age) cnt++;
	}

	cout << cnt << "마리";
	return 0;
}