/*
입력받은 3자리 문자가 몇번째 경로에서 호출되는지..
*/
#include <iostream>
#include <cstring>

using namespace std;

char arr[4];
char path[4];
int cnt = 0;

void run(int level){
	if(level == 3){
		cnt++;
		if(strcmp(path, arr) == 0){
			cout << cnt << "번째";	
		}
		return;
	}
	
	for(int i = 0; i < 4; i++){
		path[level] = i + 'A';
		run(level + 1);
		path[level] = 0;
	}
}

int main(){
	cin >> arr;
	run(0);
	return 0;
}