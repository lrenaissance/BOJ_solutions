//problem: https://www.acmicpc.net/problem/1213
//date: 20231103

#include <iostream>

using namespace std;

int main(void) {
	string s, after;
	int odd_cnt=0;
	int odd_ind=-1;
	char c;
	cin >> s;
	int* a = new int[26]();
	for (int i = 0; i < s.length(); i++) {
		a[s.at(i) - 65]++;
	}
	for (int i = 0; i < 26; i++) {
	    if (odd_cnt==0 && a[i] % 2 == 1) {//첫 홀수
			odd_ind = i;
		}
		if (a[i] % 2 == 1) {//홀수개
			odd_cnt++;
		}
	}

	if (odd_cnt == 0) {//홀수 없음
		for (int i = 0; i < 26; i++) {
			for (int k = 0; k < a[i]/2; k++) {
				after.push_back((char)(i+65));
			}
		}
		for (int i = 25; i>=0; i--) {
			for (int k = 0; k < a[i] / 2; k++) {
				after.push_back((char)(i + 65));
			}
		}
	}
	else if (odd_cnt==1) {
		for (int i = 0; i < 26; i++) { 
			for (int k = 0; k < a[i] / 2; k++) {
				after.push_back((char)(i + 65));
			}
		}
		after.push_back((char)(odd_ind + 65));
		for (int i = 25; i >= 0; i--) {
			for (int k = 0; k < a[i] / 2; k++) {
				after.push_back((char)(i + 65));
			}
		}
	}
	else {//odd_cnt > 1
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	cout << after;
	return 0;
}