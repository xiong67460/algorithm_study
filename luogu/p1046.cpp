#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10];
    for (int i = 0; i <= 9;i++){
        cin >> arr[i];
    }
    int h;
    int res = 0;
    cin >> h;
    for (int i = 0; i < 10;i++){
        if ((h+30)>=arr[i])
            res += 1;
    }
    cout << res << endl;
}