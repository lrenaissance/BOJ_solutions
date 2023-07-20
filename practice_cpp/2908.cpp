//problem: https://www.acmicpc.net/problem/2908
//date: 20230719

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    //reverse: algorithm. reverses the string. reverse(str.begin(),str.end())
    /*reverse definition : void reverse(BidirectionalIterator first, BidirectionalIterator last)
    {
        while ((first != last) && first != --last){ //last points the end of the string +1
            std::iter_swap(first++, last);
        }
    }*/
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    if (stoi(num1) > stoi(num2)) {
        cout << num1;
    }
    else {
        cout << num2;
    }

    return 0;
}