#include <iostream>
using namespace std;
void display(int arr[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void search(int arr[], int target, int n)
{
    bool con = true;
    int l = 0, r = n - 1;
    while(l<=r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            cout << "Target: " << target << " at " << mid;
            con = false;
            break;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else 
            r = mid - 1;
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