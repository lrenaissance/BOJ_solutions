//problem: https://www.acmicpc.net/problem/10951
//date: 20230919

#include <iostream>

using namespace std;

int main() {
    int a,b;
    while(cin >> a >> b){
        printf("%d\n",a+b);
    }
    return 0;
}

/*
when input number is unknown(innput 개수 모를 때)
- EOF: when there is no data to read
ex) hello(EOF)

scanf of stdioh: scanf returns int value(if correct number of inputs are read, scanf returns the number of inputs or else returns -1)
ex) scanf("%d %d", &a, &b) != -1

cin of iostream:
- eof(): returns true when it reaches the end of the file
  ex) !(cin >> a >> b).eof()
  
  wrong-ex) !cin.eof() : read first, then check eof
- ex) cin>>a>>b : returns t/f when it is inside the condition
*/