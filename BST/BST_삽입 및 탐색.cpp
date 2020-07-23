/*
다음 숫자들을 BST자료구조에 넣고
입력받은 숫자들이 존재하는지 탐색

15 7 19 8 17 25 16 18
*/
#include <iostream>
using namespace std;

int bst[100];

void insert(int value, int now = 1) {
	if (bst[now] == 0) {
		bst[now] = value;
		return;
	}

	if (bst[now] >= value) {
		insert(value, now * 2);
	}
	else {
		insert(value, now * 2 + 1);
	}
}

int search(int value, int now = 1, int lv = 1) {
	int ret = 0;
	if (now > 99) return -1;

	if (bst[now] == value) {
		return lv;
	}
	else {
		if (bst[now] >= value) {
			search(value, now * 2, lv + 1);
		}
		else {
			search(value, now * 2 + 1, lv + 1);
		}
	}
}

void init() {
	insert(15);
	insert(7);
	insert(19);
	insert(8);
	insert(17);
	insert(25);
	insert(16);
	insert(18);
}

int main() {
	init();

	int target[5];
	for (int i = 0; i < 5; i++) cin >> target[i];

	for (int i = 0; i < 5; i++) {
		int ret = search(target[i]);
		if (ret == -1) {
			cout << target[i] << ":없음" << endl;
		}
		else {
			cout << target[i] << ":" << ret << "회만에찾음" << endl;
		}
	}
}