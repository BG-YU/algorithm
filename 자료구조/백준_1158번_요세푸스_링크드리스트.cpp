#include <iostream>
using namespace std;
struct node {
	int value;
	node* left;
	node* right;
};

node* head;
node* last;
node* temp;

int main() {
	int num1, num2,cnt=1;
	cin >> num1 >> num2;

	for (int i = 1; i <= num1; i++) {
		if (head == NULL) {
			head = new node();
			head->value = i;
			last = head;
			temp = head;
		}
		else {
			last->right = new node();
			last = last->right;
			last->left = temp;
			temp = last;
			last->value = i;
		}
	}
	last->right = head;
	head->left = last;

	node* p = head;

	cout << "<";
	while (1) {
		if (cnt == num2) {
			if (!(p->value == p->right->value)) {
				cout << p->value << ", "; 
			}
			else {
				cout << p->value;
				break;
			}
			p->left->right = p->right;
			p->right->left = p->left;
			cnt = 0;

		}
		else {
			p = p->right;
			cnt++;
		}
	}
	cout << ">";

	return 0;
}