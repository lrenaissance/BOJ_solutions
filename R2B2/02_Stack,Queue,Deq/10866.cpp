//problem: https://www.acmicpc.net/problem/10866
//date: 20230719

#include <iostream>
#include <deque> //practicing deque in c++
//deque can push and pop from both sides(front and back)

using namespace std;

int main() {
    int num;
    int val;
    deque<int> dq;
    string what;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> what;
        if (what == "push_front") {
            cin >> val;
            dq.push_front(val);
        }
        if (what == "push_back") {
            cin >> val;
            dq.push_back(val);
        }
        if (what == "pop_front") {
            if (dq.empty() == true) {
                cout << -1<<"\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if (what == "pop_back") {
            if (dq.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        if (what == "size") {
            cout<<dq.size() << "\n";
        }
        if (what == "empty") {
            cout << dq.empty() << "\n";
        }
        if (what == "front") {
            if (dq.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.front() << "\n";
            }
        }
        if (what == "back") {
            if (dq.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.back() << "\n";
            }
        }

    }
    return 0;
}