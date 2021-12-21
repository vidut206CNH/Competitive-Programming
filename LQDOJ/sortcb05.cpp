#include<bits/stdc++.h>

using namespace std;

bool sortc(vector<int> a, vector<int> b) {
    if(a[0]==b[0]) return (a[1] > b[1]);
    return (a[0] > b[0]);
}

int main() {
    int n,k;
    cin >> n >> k;
    vector< vector<int> > a(n);
    for(int i=0;i<n;++i) {
        a[i].resize(2);
    }
    for(int i=0;i<n;++i) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(),a.end(),sortc);
    cout << a[k-1][0] << ' ' << a[k-1][1];

}
