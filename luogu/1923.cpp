#include<bits/stdc++.h>
using namespace std;
int arr[5000000],n,k;
int main(){
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << arr[k];
    return 0;
}
