//problem: https://www.acmicpc.net/problem/11720
//date: 20230919

#include <iostream>

using namespace std;

int main() {
    int n,sum=0;
    string s;
    cin>>n;
    cin>>s; //idea: read the number as a string
    for(int i=0;i<n;i++){
        sum+=s.at(i)-48; //can index a string by .at()
    }
    cout<<sum;
}