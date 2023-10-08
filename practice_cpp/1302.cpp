//problem: https://www.acmicpc.net/problem/1302
//date: 20231002

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string> //string 사전식 비교

using namespace std;

bool cmp(pair<string,int>&a, pair<string,int>&b){
    if(a.second==b.second){//value로 비교(사전식)
        return a<b; //시행착오: return이 아닌 a<b로 해서 틀렸었음
    }
    return a.second>b.second;//key로 비교
}

int main() {
    int n;
    string str;
    map<string,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        m[str]++;
    }
    vector<pair<string,int>> v(m.begin(),m.end()); //map->vec
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].first;
    
    return 0;
}