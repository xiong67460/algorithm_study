#include <bits/stdc++.h>
using namespace std;
double f(double x, long long N)
{
    if (N == 0)
        return 1.0;
    double y = f(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
}
double solve(double x, int n)
{
    long long N = n;
    return N >= 0 ? f(x, N) : -1.0 / f(x, N);
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << solve(x, n) << '\n';
}