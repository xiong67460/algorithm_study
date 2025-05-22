// 汉诺塔次数：2**n-1
#include <bits/stdc++.h>
using namespace std;
int move_count = 0;
void move(vector<int> &a, vector<int> &b)
{
    int pan = a.back();
    a.pop_back();
    b.push_back(pan);
    move_count++;
}
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar)
{
    if (i == 1)
    {
        move(src, tar);
        return;
    }
    dfs(i - 1, src, tar, buf);
    move(src, tar);
    dfs(i - 1, buf, src, tar);
}
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    dfs(n, A, B, C);
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B, C;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    solveHanota(A, B, C);
    for (int i : C)
        cout << i << " ";
    cout << '\n';
    cout << move_count << '\n';
    return 0;
}
