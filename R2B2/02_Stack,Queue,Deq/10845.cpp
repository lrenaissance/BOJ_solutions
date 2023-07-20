//problem: https://www.acmicpc.net/problem/10845
//date: 20230719

#include <iostream>
#include <queue> //practicing queue with c++

using namespace std;

int main() {
    int num;
    int val;
    queue<int> q;
    string what;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> what;
        if (what == "push") {
            cin >> val;
            q.push(val);
        }
        if (what == "pop") { //always consider emptiness when using pop
            if (q.empty() == true) {
                cout << -1<<"\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if (what == "size") {
            cout<<q.size() << "\n";
        }
        if (what == "empty") { //rear==front -> empty, (rear+1)%size==front -> full
            cout << q.empty() << "\n";
        }
        if (what == "front") {
            if (q.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        if (what == "back") {
            if (q.empty() == true) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }

    }
    return 0;
}