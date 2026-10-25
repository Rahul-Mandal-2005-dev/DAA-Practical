#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void Sorting(vector<string> &name, vector<int> &salary, int st, int mid, int end)
{
    int i = st, j = mid + 1;
    vector<string> tempName;
    vector<int> tempSalary;
    while (i <= mid && j <= end)
    {
        if (salary[i] <= salary[j])
        {
            tempSalary.push_back(salary[i]);
            tempName.push_back(name[i]);
            i++;
        }
        else
        {
            tempSalary.push_back(salary[j]);
            tempName.push_back(name[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tempSalary.push_back(salary[i]);
        tempName.push_back(name[i]);
        i++;
    }
    while (j<=end)
    {
        tempSalary.push_back(salary[j]);
        tempName.push_back(name[j]);
        j++;
    }

    for(int k = 0;k<tempSalary.size();k++)
    {
        name[k+st] = tempName[k];
        salary[k+st] = tempSalary[k];
    }
}

void MergeSort(vector<string> &name, vector<int> &salary, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        MergeSort(name, salary, st, mid);
        MergeSort(name, salary, mid + 1, end);

        Sorting(name, salary, st, mid, end);
    }
}

void display(vector<string> name, vector<int> salary, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Name " << i + 1 << ": " << name[i] << "\tSalary " << i + 1 << ": " << salary[i];
        cout << "\n";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cout << "Enter Arr size: ";
    cin >> n;
    int s;
    string na;
    vector<int> salary;
    vector<string> name;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Name " << i + 1 << ": ";
        getline(cin, na);
        name.push_back(na);

        cout << "Enter Salary " << i + 1 << ": ";
        cin >> s;
        salary.push_back(s);
        cin.ignore();
    }

    int st = 0, end = n - 1;
    display(name, salary, n);
    MergeSort(name, salary, st, end);
    display(name, salary, n);

    return 0;
}