#include <iostream>
#include <algorithm>
using namespace std;

void sorting(int jobs[], int profit[], int deadline[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit[j] < profit[j + 1])
            {
                swap(profit[j], profit[j + 1]);
                swap(jobs[j], jobs[j + 1]);
                swap(deadline[j], deadline[j + 1]);
            }
        }
    }
}

void display(int jobs[], int profit[], int deadline[], int n)
{
    cout << "Jobs\t\tProfile\t\tDeadline\n";
    for (int i = 0; i < n; i++)
    {
        cout << jobs[i] << "\t\t" << profit[i] << "\t\t" << deadline[i] << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter Num of Jobs: ";
    cin >> n;

    int jobs[n], profit[n], deadline[n];
    for (int i = 0; i < n; i++)
    {
        jobs[i] = i + 1;

        cout << "Profile " << i + 1 << ": ";
        cin >> profit[i];

        cout << "Deadline " << i + 1 << ": ";
        cin >> deadline[i];
    }
    cout << "Job Sequence: \n\n";
    display(jobs, profit, deadline, n);
    sorting(jobs, profit, deadline, n);

    cout << "Sorted Job Sequence\n\n";
    display(jobs, profit, deadline, n);

    int slot[n+1] = {0};
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(deadline[i],n); j > 0; j--)
        {
            if (j <= n && slot[j] == 0)
            {
                slot[j] = jobs[i];
                total += profit[i];
                break;
            }
        }
    }
    
    cout <<"\nSlots - ";
    for (int i = 1; i <= n; i++)
    {
        if (slot[i] != 0)
        {
            cout<<"J"<<slot[i] << " ";
        }
    }
    
    cout << "\nTotal Profit: " << total;

    return 0;
}