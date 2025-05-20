#include <bits/stdc++.h>
using namespace std;
int maxProductCutting(int n)
{
    if (n <= 3)
        return (n - 1);
    int a = n / 3;
    int b = n % 3;
    if (b == 1)
        return (int)pow(3, a - 1) * 4;
    else if (b == 2)
        return (int)pow(3, a) * 2;
    else
        return (int)pow(3, a);
}
int main(){
    int n;
    cin >> n;
    cout << maxProductCutting(n) << '\n';
}