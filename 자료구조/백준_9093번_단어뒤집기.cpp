/*
문제
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.

예제 입력 1
2
I am happy today
We want to win the first prize

예제 출력 1
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