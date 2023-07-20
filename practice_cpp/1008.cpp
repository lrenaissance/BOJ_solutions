//problem: https://www.acmicpc.net/problem/1008
//date: 20230719

#include <iostream>

using namespace std;

int main(void){
    int a,b;
    cin>>a>>b;
    //had to add a precision because of the error condition
    //cout << fixed; -> only considers the digits under the decimal point
    cout.precision(10); //prints the (actual) number as 10 digits
    //ex) precision(5) -> 123.45

    cout<<(double)a/b;
    return 0;
}