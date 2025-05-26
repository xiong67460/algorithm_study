#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, n;//n为小数点后位数
    cin >> a >> b >> n;
    cout << a / b << '.';
    int t = a % b;
    for (int i = 0; i < n; i++){
        t *= 10;
        cout << t / b;
        t %= b;
    }
    return 0;
}