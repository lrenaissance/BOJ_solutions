//problem: https://www.acmicpc.net/problem/1620
//date: 20230718

#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //enhancing i/o speed

    int p_num, q_num;
    string name;
    string input;
    map<int,string> enc;
    map<string, int> enc2;

    cin >> p_num>>q_num;
    for (int i = 0; i < p_num; i++) {
        cin >> name;
        enc.insert({ i+1, name });
        enc2.insert({ name, i+1 }); //made an extra map instead of finding the value by key(value로 key를 찾는 것보다 그냥 맵 하나를 더 만들었음)
    }
    for (int i = 0; i < q_num; i++) {
        cin >> input;
        if (isdigit(input[0]) != 0) {//when input is a number(숫자가 입력될 때) //isdigit: cctype. whether char is a digit(숫자인지 판단해줌)
            cout << enc[stoi(input)] << "\n"; //stoi: string. string->int
        }
        else {//when input is a string
            cout << enc2[input] << "\n";
        }
    }
    return 0;
}