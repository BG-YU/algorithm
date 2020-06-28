/*
����
�� �ٷ� �� ������ �����͸� �����Ϸ��� �Ѵ�. �� ������� ���� �ҹ��ڸ��� ����� �� �ִ� �������, �ִ� 600,000���ڱ��� �Է��� �� �ִ�.
�� �����⿡�� 'Ŀ��'��� ���� �ִµ�, Ŀ���� ������ �� ��(ù ��° ������ ����), ������ �� ��(������ ������ ������), �Ǵ� ���� �߰� ������ ��(��� ���ӵ� �� ���� ����)�� ��ġ�� �� �ִ�. �� ���̰� L�� ���ڿ��� ���� �����⿡ �ԷµǾ� ������, Ŀ���� ��ġ�� �� �ִ� ���� L+1���� ��찡 �ִ�.
�� �����Ⱑ �����ϴ� ��ɾ�� ������ ����.

L	Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
D	Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
B	Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
    ������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
P $	$��� ���ڸ� Ŀ�� ���ʿ� �߰���

�ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ��� �־�����, �� ���� �Է��� ��ɾ ���ʷ� �־����� ��, ��� ��ɾ �����ϰ� �� �� �����⿡ �ԷµǾ� �ִ� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ��ɾ ����Ǳ� ���� Ŀ���� ������ �� �ڿ� ��ġ�ϰ� �ִٰ� �Ѵ�.

�Է�
ù° �ٿ��� �ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ��� �־�����. �� ���ڿ��� ���̰� N�̰�, ���� �ҹ��ڷθ� �̷���� ������, ���̴� 100,000�� ���� �ʴ´�. ��° �ٿ��� �Է��� ��ɾ��� ������ ��Ÿ���� ���� M(1 �� M �� 500,000)�� �־�����. ��° �ٺ��� M���� �ٿ� ���� �Է��� ��ɾ ������� �־�����. ��ɾ�� ���� �� ���� �� �ϳ��� ���·θ� �־�����.

���
ù° �ٿ� ��� ��ɾ �����ϰ� �� �� �����⿡ �ԷµǾ� �ִ� ���ڿ��� ����Ѵ�.

���� �Է� 1
abcd
3
P x
L
P y

���� ��� 1
abcdyx

���� �Է� 2
abc
9
L
L
L
L
L
P x
L
B
P y

���� ��� 2
yxabc

���� �Է� 3
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z

���� ��� 3
yxz
*/

#include <iostream>
using namespace std;

struct node {
	char value;
	node* left;
	node* right;
};

node* head;
node* last;
node* now;

void addnode(char value) {
	if (head == NULL) {
		head = new  node();
		head->value = value;
		last = head;
		now = head;
	}
	else {
		last->right = new node();
		last = last->right;
		last->value = value;
		last->left = now;
		now = last;
	}
}

void deletenode(node* temp) {
	if (temp->left != NULL) temp->left->right = temp->right;
	else head = head->right;

	if (temp->right != NULL) temp->right->left = temp->left;
}

void insertnode(node* temp, int value) {
	node* p = head;
	if (temp->left == NULL) {
		head = new node();
		head->value = value;
		head->right = p;
		temp->left = head;
	}
	else {
		node* tmp = new node();
		node* tmp1 = temp->left;

		tmp->value = value;

		temp->left = tmp;
		tmp->right = temp;
		tmp->left = tmp1;
		tmp1->right = tmp;
	}
}

int main() {
	char arr[600001], cmd1, cmd2;
	int num;
	cin >> arr;

	for (int i = 0; i < 600000; i++) {
		if (arr[i] == '\0') break;
		addnode(arr[i]);
	}
	addnode('\0');

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> cmd1;
		if (cmd1 == 'P') cin >> cmd2;

		switch (cmd1) {
		case 'L':
			if (now->left == NULL) continue;
			now = now->left;
			break;
		case 'D':
			if (now->right == NULL) continue;
			now = now->right;
			break;
		case 'B':
			if (now->left == NULL) continue;
			deletenode(now->left);
			break;
		case 'P':
			insertnode(now, cmd2);
			break;
		}
	}

	node* p = head;

	while (1) {
		if (p == NULL || p->value == '\0') break;
		cout << p->value;
		p = p->right;
	}

	return 0;
}