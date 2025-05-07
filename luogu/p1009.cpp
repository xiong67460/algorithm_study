#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int temp = 1;
    long long int sum = 0;
    for (int i = 1; i <= n;i++){
        temp *= i;
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}