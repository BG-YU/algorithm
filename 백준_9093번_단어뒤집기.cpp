/*
����
������ �־����� ��, �ܾ ��� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ܾ��� ������ �ٲ� �� ����. �ܾ�� ���� ���ĺ����θ� �̷���� �ִ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ������ �ϳ� �־�����. �ܾ��� ���̴� �ִ� 20, ������ ���̴� �ִ� 1000�̴�. �ܾ�� �ܾ� ���̿��� ������ �ϳ� �ִ�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ������ �ܾ ��� ������ ����Ѵ�.

���� �Է� 1
2
I am happy today
We want to win the first prize

���� ��� 1
I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void fn_print(char* arr) {
	for (int i = strlen(arr) - 1; i >= 0; i--) {
		cout << arr[i];
	}
}

int main() {
	string str;
	char word[21];
	int num, cnt = 0;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		getline(cin, str);
		for (int k = 0; k < 1000; k++) {
			if (str[k] == '\0') break;
			if (str[k] == ' ') continue;
			word[cnt++] = str[k];
			if (str[k + 1] == ' ' || str[k + 1] == '\0') {
				word[cnt] = '\0';
				fn_print(word);
				cout << " ";
				cnt = 0;
			}
		}
	}

	return 0;
}