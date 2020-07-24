/*
입력 받은 level 깊이 만큼 탐색한후, 경로 출력
*/

#include <iostream>
using namespace std;

int num;
char path[10];
char arr[5] = "BGTK";

void run(int level){
	if(level == num){
		for(int i = 0; i < level; i++){
			cout << path[i];
		}
		cout << endl;
		return;
	}
	
	for(int i = 0; i < 4; i++){
		path[level] = arr[i];
		run(level + 1);
		path[level] = 0;
	}
}

int main(){
	cin >> num;
	run(0);
	return 0;
}