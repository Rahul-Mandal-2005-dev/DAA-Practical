#include <iostream>
using namespace std;
void sorting(int profile[], int weight[], double ratio[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(profile[j], profile[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }
}

double profit_cal(int profile[], int weight[], double ratio[], int n, int M)
{   
    double P = 0;
    for(int i = 0;i < n; i++){
        if(M >= weight[i])
        {
            P += profile[i];
            M -= weight[i];
        }
        else{
            P += (profile[i]*((double)M/weight[i]));
            break;
        }
    }
    return P;
}
int main()
{
    int n;
    cout << "Enter Num of Object: ";
    cin >> n;

    int profile[n], weight[n];
    double ratio[n];
    int M;
    cout << "Enter Size (M): ";
    cin >> M;

    for (int i = 0; i < n; i++)
    {
        cout << "Profile " << i + 1 << ": ";
        cin >> profile[i];

        cout << "Weight " << i + 1 << ": ";
        cin >> weight[i];

        ratio[i] = (double)profile[i] / weight[i];
    }

    sorting(profile, weight, ratio, n);
    
    double output = profit_cal(profile, weight, ratio, n,M);
    cout<<"Total Profit: "<<output;
    
    return 0;
}