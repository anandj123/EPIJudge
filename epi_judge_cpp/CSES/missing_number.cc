#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector<int> arr(n-1);
    for(int i=0;i<n-1;++i) cin >> arr[i];
    sort(arr.begin(),arr.end());
    bool found = false;
    for(int i=1;i<n-1;++i){
        if (arr[i] - arr[i-1] -1) {
            cout << arr[i]-1;
            found = true;
            break;
        }
    }
    if (!found) {
        if (arr[n-2] == n) {
            cout << (arr[0] - 1);
        } else {
            cout << (arr[n-2] + 1);
        }
    }
    cout << endl;
}