//problem: https://www.acmicpc.net/problem/1735
//date: 20230725

#include <iostream>
#include <algorithm>

using namespace std;

struct frac{//fraction
  int numer,denom;//numerator, denominator
};

int euc_method(int a,int b){//euclidean method
    while(b!=0){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main(void) {
   frac a,b,ans;
   cin>>a.numer>>a.denom;
   cin>>b.numer>>b.denom;
   
   int gcd;
   //g*l=a*b only works when a and b are coprime
   a.numer=a.numer*b.denom;
   b.numer=b.numer*a.denom;
   ans.numer=a.numer+b.numer;
   ans.denom=a.denom*b.denom;
   
   if(ans.denom>ans.numer){ //added this condition to make a>b for euc_method
       gcd=euc_method(ans.denom,ans.numer);    
   }
   else{
       gcd=euc_method(ans.numer,ans.denom);
   }
   if(gcd==1){//they are coprime
       cout<<ans.numer<<" "<<ans.denom;
   }
   else{//they can be reducted
       cout<<ans.numer/gcd<<" "<<ans.denom/gcd; 
   }
   
    return 0;
}