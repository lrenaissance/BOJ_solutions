//problem: https://www.acmicpc.net/problem/1918
//date: 20230930

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { //push만 하기
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (s.top()!= '(') { //괄호 안 내용 모두 pop
				printf("%c", s.top());
				s.pop();
			}
			s.pop();// (처리
		}
		else if (str[i] =='*' || str[i] == '/') {
			if (s.empty() == 1 ||s.top()=='+' || s.top() == '-') { //빈 스택(top() 함수 주의)
				s.push(str[i]);
				continue;
			}
			while (s.empty() != 1 && s.top() != '('&&(s.top()=='*'|| s.top()=='/')) { 
        //스택 pop()(+나 - 나오면 pop 멈추기를 조건에 추가해줘야함)
				printf("%c", s.top());
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			if (s.empty()== 1) { //빈 스택(top() 함수 주의
				s.push(str[i]);
				continue;
			}
			//
			while (s.empty()!=1 && s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			}
			s.push(str[i]);
		}
		else{ //str[i]==operand
			printf("%c", str[i]);
		}
	}
	while (s.empty() != 1) {//스택 비우기
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}

/*시행착오: 후위표기식을 이해하는 것이 어려웠음. 스택에 +가 들어있는 상태에서 *가 들어왔을 때 처리 방법이 헷갈렸음...
질문 게시판에 있는 반례들 넣어보면서 빠진 조건들을 계속 찾아보았음.*/