#include<bits/stdc++.h>

using namespace std;

int arr[1000001];


int main() {
    memset(arr,0,sizeof(arr));
    int n;
    cin >> n;
    int arr1[n];
    for(int i=0;i<n;++i) {
        cin >> arr1[i];
        arr[arr1[i]] += 1;
    }
    for(int i=0;i<n;++i) {
        cout << arr1[i] << ' ' << arr[arr1[i]];
        cout << '\n';
    }

}
