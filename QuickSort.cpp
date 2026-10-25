#include <iostream>
using namespace std;
void display(int arr[],int n){
    cout << "Array : " ;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout<<"\n";
}
int Sorting(int arr[], int st, int end)
{
    int i = st - 1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}

void QuickSort(int arr[], int st, int end)
{
    if (st < end)
    {
        int partition = Sorting(arr, st, end);
        QuickSort(arr, st, partition - 1);
        QuickSort(arr, partition + 1, end);
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
    display(arr,n);
    int st = 0, end = n - 1;
    QuickSort(arr, st, end);
    display(arr,n);
    
    return 0;
}