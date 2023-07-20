//problem: https://www.acmicpc.net/problem/10828
//date: 20230719

#include <iostream>
#include <stack> //practicing stack in c++

using namespace std;

int main() {
    int num;
    int val;
    stack<int> s;
    string what;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> what;
        if (what == "push") {
            cin >> val;
            s.push(val);
        }
        if (what == "pop") {
            if (s.empty() == true) {
                cout << -1<<"\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        if (what == "size") {
            cout<<s.size() << "\n";
        }
        if (what == "empty") {
            cout << s.empty() << "\n";
        }
        if (what == "top") { //top checks the top element of stack without popping. must check the stack's emptiness
            if (s.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}