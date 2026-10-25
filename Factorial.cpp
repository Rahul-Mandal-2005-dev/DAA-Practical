#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Num: ";
    cin>>n;
    int mul = 1;
    for(int i = 1; i<=n;i++){
        mul *=i;
    }
    cout<<"Factorial: "<<mul;
    return 0;
}