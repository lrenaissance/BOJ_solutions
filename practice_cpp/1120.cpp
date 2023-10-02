//problem: https://www.acmicpc.net/problem/1120
//date: 20230930

#include <iostream>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	if (a.length() == b.length()) {
		int cnt = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				cnt++;
			}
		}
		printf("%d", cnt);
	}
	else{
		string l,s;
		if (a.length() < b.length()) {
			s = a;
			l = b;
		}
		else {
			s = b;
			l = a;
		}
		int* cnt = new int[l.length()-s.length()+1]();
		int min;
		for (int i = 0; i <= l.length()-s.length(); i++) {
			for (int k = 0; k < s.length(); k++) {
				int p = k + i;
				if (s[k]!= l[p]) {
					cnt[i]++;
				}
			}
			if (i == 0) {
				min = cnt[0];
			}
			else if (min > cnt[i]) {
				min = cnt[i];
			}
		}
		printf("%d", min);
	}
	return 0;
}

/*짧은 문자열을 긴 문자열과 많이 겹치는 부분과 맞춘 후, 긴 문자열에 맞게 
아무 알파벳을 추가하면 되므로 추가하는 알파벳은 신경쓰지 않아도 됨. 
긴 문자열 내에서 여러번 탐색해서 짧은 문자열과 최대한 겹치는 부분을 찾아야함*/