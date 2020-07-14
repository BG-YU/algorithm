/*
B, I, A, H 슈퍼영웅들 중 출동할 사람을 순서대로 뽑아야 합니다.
척척박사님은 자신의 이름이 다섯글자이기에 영웅B를 시작으로 n번째 사람을 선택합니다.
출동하는 영웅들의 순서를 출력 하세요.
(큐를 이용하지 않고, For문 or While문을 활용해서 풀어주세요)
만약 5를 입력받았다면,
항상 다섯번째 사람을 먼저 출동시키면 됩니다.

BIAH
1234
5
B출력

BIAH
 123
 45
A출력

BIAH
   1
 2 3
 4 5
H출력
*/

/*
모범답안?
#include<iostream>
using namespace std;

char hero[4] = { 'B', 'I', 'A', 'H' };
int used[4];

int findNext(int i)
{
	for (int x = 1; x <= 4; x++) {
		int select = (i + x) % 4;
		if (used[select] == 0) return select;
	}
	return 0;
}

int main()
{
	int countDown;
	int target;
	int now;

	cin >> countDown;

	target = -1;
	for (int i = 0; i < 4; i++) {

		//타겟 선정
		for (int x = 0; x < countDown; x++)	{
			target = findNext(target);
		}

		//선택완료
		cout << hero[target] << " ";
		used[target] = 1;
	}
	return 0;
}
*/
#include <iostream>
using namespace std;

int main() {
	int num;

	struct node {
		char chr;
		node* left;
		node* right;
	};

	node* head = new node();
	head->chr = 'B';
	head->right = new node();
	head->right->left = head;
	head->right->chr = 'I';
	head->right->right = new node();
	head->right->right->chr = 'A';
	head->right->right->left = head->right;
	head->right->right->right = new node();
	head->right->right->right->chr = 'H';
	head->right->right->right->right = head;
	head->right->right->right->left = head->right->right;
	head->left = head->right->right->right;

	cin >> num;
	node* temp = new node();
	while (1) {
		for (int i = 0; i < num; i++) {
			if (temp->chr == NULL) {
				temp = head;
			}
			else {
				temp = temp->right;
			}
		}

		cout << temp->chr << " ";
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		if (temp->left->chr == temp->right->chr) {
			cout << temp->right->chr << " ";
			break;
		}
	}

	return 0;
}