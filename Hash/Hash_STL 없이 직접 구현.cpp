#include <iostream>
using namespace std;

struct Node {
	char ch;
	Node* next;
};

Node buf[100]; // MemoryPool
int bufCnt;

Node* head;

Node* myAlloc(int ch, Node* next) {
	buf[bufCnt].ch = ch;
	buf[bufCnt].next = next;
	return &buf[bufCnt++];
}

void addNode(char ch, Node* next) {
	head = myAlloc(ch, head);
}

char hashf(char ch) {
	// 여기에 해쉬 시킬 계산 로직을 넣어준다.
	// ex) ch %= 5; 
	return ch;
}

int main() {
	addNode(hashf('A'), head);
	addNode(hashf('B'), head);
	addNode(hashf('C'), head);
	addNode(hashf('D'), head);
	addNode(hashf('E'), head);

	for (int i = 0; i < 100; i++) {
		if (buf[i].ch == '\0') break;
		cout << buf[i].ch << " ";
	};

	return 0;
}