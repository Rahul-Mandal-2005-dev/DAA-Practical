#include <iostream>
#include <climits>
using namespace std;
int n, cost[10][10], dp[1024][10];
int tsp(int mark, int pos)
{
    if (mark == (1 << n) - 1)
        return cost[pos][0];
    if (dp[mark][pos] != -1)
        return dp[mark][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if(!(mark & (1<<city)))
        {
           int newCost = cost[pos][city]+tsp(mark|(1<<city),city);

           if(newCost < ans)
           {
            ans = newCost;
           }
        }
    }
    return dp[mark][pos] = ans;
}
int main()
{
    cout << "Enter num of cities: ";
    cin >> n;

    cout << "Matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum cost: " << tsp(1, 0);

    return 0;
}