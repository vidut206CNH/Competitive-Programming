#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[n];
    int i;
    string k;
    for(int j=0;j<n/2;++j) {
        cin >> i >> k;
        arr[i] += "- ";
    }
    for(int j=n/2;j<n;++j) {
        cin >> i >> k;
        arr[i] += (k + " ");
    }
    for(int j=0;j<n;++j) cout << arr[j];
}
