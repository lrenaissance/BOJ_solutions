//problem: https://www.acmicpc.net/problem/4949
//date: 20230922

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void balance(string str, stack<char>& s) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
        }
        if (str[i] == ')' || str[i] == ']') {
            if (s.empty() == 1) {
                cout << "no" <<"\n";
                return;
            }
            if ((s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']')) {
                s.pop();
            }
            else{
                cout << "no" <<"\n";
                return;
            }
        }
    }
    if (s.empty() == 0) {
        cout << "no" <<"\n";
        return;
    }
    if (s.empty() == 1) {
        cout << "yes" <<"\n";
        return;
    }
}

int main() {
    string str = "";
    while (true) {
        getline(cin, str);
        if (str == ".") {
            break;
        }
        stack<char> s;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        balance(str, s);
    }
    return 0;
}

/*사고 과정: 짝을 이루는지 확인하는 것을 스택을 통해 해결하면 좋겠다는 생각을 함
- (, [가 들어오면 push, ), ]는 stack의 top이 (, [에 대응될 때만 pop
- 오류: no를 리턴할 때를 오른쪽 소괄호가 빈 스택에 들어갈 때, 스택 과정이 끝났는데 스택이 비어있지 않을 때로만 한정해서 (])와 같은 테스트케이스를 넣었을 때 yes를 도출해내는 오류가 있었다. 조건문을 써서 특정 상황 판단을 할 때는 else 상황도 반드시 생각해보자.
*/