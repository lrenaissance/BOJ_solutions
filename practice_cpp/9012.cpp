//problem: https://www.acmicpc.net/problem/9012
//date: 20230902

#include <iostream>
#include <stack>
#include <string>

using namespace std;
//used: stack
void check(string s) {
	stack <char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else if (s[i] == ')') {
			if(st.empty()!=1 && st.top()=='('){
				st.pop();
			}
			else {
				printf("NO\n");
				break;
			}
		}
		if (i == s.length() - 1) {
			if (st.empty() == 1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}

int main(void) {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		check(s);
	}
	
	return 0;
}