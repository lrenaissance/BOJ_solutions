//problem: https://www.acmicpc.net/problem/10814
//date: 20231007

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct member{
    string name;
    int age,order;
};
bool cmp(member a,member b){
    if(a.age==b.age)
        return a.order<b.order;
    return a.age<b.age;
}
int main() {
    int n;
    cin>>n;
    member *list=new member[n];
    for(int i=0;i<n;i++){
        cin>>list[i].age>>list[i].name;
        list[i].order=i;
    }
    sort(list,list+n,cmp);
    for(int i=0;i<n;i++){
        cout<<list[i].age<<" "<<list[i].name<<"\n";
    }
    return 0;
}