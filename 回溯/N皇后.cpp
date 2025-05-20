#include <bits/stdc++.h>
using namespace std;
void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res, vector<bool> &cols, vector<bool> &diags1, vector<bool> &diags2)
{
    if (row == n)
    {
        res.push_back(state);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        if (!cols[col] && !diags1[diag1] && !diags2[diag2])
        {
            state[row][col] = "Q";
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            state[row][col] = "#";
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}
vector<vector<vector<string>>> nQueens(int n)
{
    vector<vector<vector<string>>> res;
    vector<vector<string>> state(n, vector<string>(n, "#"));
    vector<bool> cols(n, false);
    vector<bool> diags1(2 * n - 1, false);
    vector<bool> diags2(2 * n - 1, false);
    backtrack(0, n, state, res, cols, diags1, diags2);
    return res;
}
int main()
{
    int n = 5;
    auto solutions = nQueens(n);
    for (const auto &board : solutions)
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                cout << cell;
            }
            cout << '\n';
        }
        cout << "--------\n";
    }
    return 0;
}
