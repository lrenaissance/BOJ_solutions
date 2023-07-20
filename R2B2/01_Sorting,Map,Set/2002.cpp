//problem: https://www.acmicpc.net/problem/2002
//date: 20230719

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int cnt,cars=0;
    string name;
    cin >> cnt;
    map<string, int> cars_in; //used map to record the name of the car and its index
    vector<string> cars_out;

    for (int i = 0; i < cnt; i++) {//incoming cars
        cin >> name;
        cars_in[name] = i;
    }
    for (int i = 0; i < cnt; i++) {//outgoing cars
        cin >> name;
        cars_out.push_back(name);
    }

    for (int i = 0; i < cnt-1; i++) {
        for (int j = i+1; j < cnt; j++) { //started j with i+1
            if (cars_in[cars_out[i]] > cars_in[cars_out[j]]) {
                cars++;
                break; //only breaks the current for loop
            }
        }
    }

    cout << cars;

    return 0;
}