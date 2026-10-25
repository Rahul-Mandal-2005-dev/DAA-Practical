#include <iostream>
using namespace std;
int main(){
    // factorial combination - 0 1 1 2 3 5 8 13 21 34 55

    int n;
    cout<<"Enter Num: ";
    cin>>n;
    // int a = 0,b = 1;
    // int c;
    // int i = 1;
    // while(i<n){
    //     c = a+b;
    //     a = b;
    //     b = c;
    //     i++;
    // }
    // cout<<a;
    
    int a = 0,b = 1;
    int c;
    int i = 1;
    while(i<n){
        cout<<a<<" ";
        c = a+b;
        a = b;
        b = c;
        i++;
    }
    return 0;
}