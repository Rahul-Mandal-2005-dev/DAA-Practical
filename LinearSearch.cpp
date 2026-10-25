#include <iostream>
using namespace std;
int display(int arr[], int n)
{   cout<<"Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int search(int arr[], int target, int n)
{
    bool con = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            cout << "Target: " << target << " at idx: " << i;
            con = false;
        }
    }
    if (con)
    {
        cout << "Target Not Found";
    }
}
int main()
{
    int n;
    cout << "Enter Arr size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr " << i + 1 << ": ";
        cin >> arr[i];
    }
    display(arr, n);
    int target;
    cout << "\nEnter Target: ";
    cin >> target;
    search(arr, target, n);

    return 0;
}