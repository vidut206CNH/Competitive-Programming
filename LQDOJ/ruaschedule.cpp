#include<bits/stdc++.h>

using namespace std;

bool sortc(vector<string> a, vector<string> b) {
    for(int i=0;i<5;++i) {
        if(a[0][i] != b[0][i]) return (a[0][i]<b[0][i]);
    }

}

int main() {
    int n;
    cin>>n;
    vector< vector<string> > a(n);
    for(int i=0;i<n;++i) {
        a[i].resize(2);
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(),a.end(),sortc);
    for(int i=0;i<n;++i) {
        cout << a[i][0] << ' ' << a[i][1] << '\n';
    }


}
