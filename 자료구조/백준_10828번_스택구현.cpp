/*
����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
14
push 1
push 2
top
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
top

���� ��� 1
2
2
0
2
1
-1
0
1
-1
0
3

���� �Է� 2
7
pop
top
push 123
top
pop
top
pop

���� ��� 2
-1
-1
123
123
-1
-1
*/


#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char comm1[6];
	int comm2, num, cnt = 0;
	cin >> num;
	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> comm1;
		if (strcmp(comm1, "push") == 0) cin >> comm2;

		if (strcmp(comm1, "push") == 0) {
			arr[cnt++] = comm2;
		}
		else if (strcmp(comm1, "pop") == 0) {
			if (cnt == 0) {
				cout << -1 << endl;
			}
			else {
				cnt--;
				cout << arr[cnt] << endl;
			}
		}
		else if (strcmp(comm1, "size") == 0) {
			cout << cnt << endl;
		}
		else if (strcmp(comm1, "empty") == 0) {
			if (cnt > 0) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else if (strcmp(comm1, "top") == 0) {
			if (cnt == 0) cout << -1 << endl;
			else cout << arr[cnt - 1] << endl;
		}
	}

	delete[] arr;
	return 0;
}