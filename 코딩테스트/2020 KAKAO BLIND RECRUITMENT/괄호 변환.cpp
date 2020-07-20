/*
2020 KAKAO BLIND RECRUITMENT
괄호 변환
https://programmers.co.kr/learn/courses/30/lessons/60058
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//vector<char> ret;

string ret = "";

int fn_chk(string p) {
	vector<char> temp;
	for (int i = 0; i < p.length(); i++) {
		temp.push_back((char)(p[i]));
		
		if (temp.size() >= 2) {
			if (temp[temp.size() - 1] == ')' && temp[temp.size() - 2] == '(') {
				temp.pop_back();
				temp.pop_back();
			}
		}
	}

	return temp.size();
}

void run(string u, string v) {
	int cnt = 0;
	string str1 = "", str2 = "", temp = "";
	int u_cnt = fn_chk(u);
	if (u_cnt == 0) {
		ret += u;
		run(v, "");
	}
	else {
		if (u_cnt == u.length()) {
			int left = u.length() / 2 - 1;
			int right = u.length() / 2;

			for (int i = 0; i < u.length() / 2; i++) {
				if ((char)(u[left]) == '(' && (char)(u[right]) == ')') {
					left--;
					right++;
				}
				else {
					u[left] = '(';
					u[right] = ')';
					left--;
					right++;
				}
			}
			temp += u;
			temp += v;
			ret += temp;
			return;
		}
		else {
			for (int i = 0; i < u.length(); i++) {
				str1 += (char)(u[i]);

				if ((char)(u[i]) == '(') cnt++;
				else cnt--;

				if (cnt == 0) {
					for (int k = str1.length(); k < u.length(); k++) {
						str2 += (char)(u[k]);
					}
					run(str1, str2);
					break;
				}
			}
		}
	}
}

int main() {
	string p = ")(";
	string answer = "";
	string u = "", v = "";
	int cnt = 0;

	if (fn_chk(p) == 0 || p == "") {
		cout << p;
		return 0;
	}

	for (int i = 0; i < p.length(); i++) {
		u += (char)(p[i]);
		if ((char)(p[i]) == '(') cnt++;
		else cnt--;
		if (cnt == 0) {
			if (fn_chk(u) == 0) {
				for (int k = u.length(); k < p.length(); k++) {
					v += (char)(p[k]);
				}
				run(u, v);
				break;
			}
			else {
				run(u, v);
			}
			
		}
	}

	cout << ret;

	return 0;
}