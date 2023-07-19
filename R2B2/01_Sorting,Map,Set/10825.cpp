//problem: https://www.acmicpc.net/problem/10825
//date: 20230718

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int korean, english, math;
};

bool comp(student a, student b) { //the first comp function I made(inefficient)
    if (a.korean == b.korean) { //same kor score
        if (a.english == b.english) {
            if (a.math == b.math) {
                return a.name < b.name;
            }
            else {//different math score
                return a.math > b.math;
            }
        }
        else {//different eng score
            return a.english < b.english;
        }
    }
    else { //different kor score
        return a.korean > b.korean;
    }
}

bool comp2(student a, student b){ //better than comp
  if(a.korean!=b.korean){
    return a.korean>b.korean;
  }
  if(a.english!=b.english){
    return a.english < b.english;
  }
  if(a.math!=b.math){
    return a.math > b.math;
  }
  return a.name < b.name;
}

int main() {
    vector<student> info;
    string name;
    int kor,eng,math,num = 0;

    cin >> num; //using scanf had an segmentation fault
    for (int i = 0; i < num; i++) {
        cin >> name >> kor >> eng >> math;
        info.push_back({name,kor,eng,math}); 
        //At first, I used info.[i].korean but this had leaded to an OutofBounds exception because I have declared info without specific size.
        //always remeber to use push_back when no size is chosen.
    }
    //sort: algorithm. (starting addr, end addr+1, sorting criteria). swaps when sorting criteria returns false.
    sort(info.begin(), info.end(), comp2); //not comp(). just comp.

    for (int i = 0; i < num;i++) {
        cout <<info[i].name<< "\n";
    }

    return 0;
}