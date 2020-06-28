/*
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front

���� ��� 1
1
2
2
0
1
2
-1
0
1
-1
0
3
*/

#include <iostream>
using namespace std;

int arr[10000];

int main() {
	int num, cmd2, cnt = -1, front = 0, size = 0;
	char cmd1[6];
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> cmd1;
		if (cmd1[0] == 'p' && cmd1[1] == 'u') cin >> cmd2;

		switch (cmd1[0]) {
		case 'p':
			switch (cmd1[1]) {
			case 'u':
				arr[++cnt] = cmd2;
				size++;
				break;
			case 'o':
				if (cnt == -1) cout << -1 << "\n";
				else {
					cout << arr[front] << "\n";
					arr[front] = '\0';
					front++;
					size--;
					if (size == 0) {
						front = 0;
						cnt = -1;
					}
				}
				break;
			}
			break;
		case 's':
			cout << size << "\n";
			break;
		case 'e':
			if (size == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 'f':
			if (size == 0) cout << -1 << "\n";
			else cout << arr[front] << "\n";
			break;
		case 'b':
			if (size == 0) cout << -1 << "\n";
			else cout << arr[cnt] << "\n";
			break;
		}

	}
}