#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n)
{
    // Horizontally
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }
    // Vertically
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    // Left Diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // Right Diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}
void NQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back({board});
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            NQueen(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}
int main()
{
    int n;
    cout << "Enter Board size: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    int row = 0;
    NQueen(board, row, n, ans);

    cout << "\nTotal solutions: " << ans.size() << "\n";

    for (int k = 0; k < (int)ans.size(); k++)
    {
        cout << "\nSolution " << k + 1 << ":\n";

        for (int i = 0; i < n; i++)
        {
            cout << ans[k][i] << "\n";
        }
    }
    return 0;
}