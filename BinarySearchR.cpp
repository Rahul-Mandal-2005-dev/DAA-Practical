#include <iostream>
using namespace std;
int binarySearch(int arr[],int l, int r,int target)
{
    if (l > r) return -1;

    int mid = (l+r)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target)
        return binarySearch(arr,mid+1,r,target);
    else
        return binarySearch(arr,l,mid-1,target);   
}
void display(int arr[], int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
    int l = 0, r = n - 1;
    int result = binarySearch(arr, l, r,target);

    if (result == -1)
        cout << "Target not found";
    else
        cout << "Traget: "<< target << " at " << result;
    return 0;
}
