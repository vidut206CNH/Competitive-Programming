#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    char c;
    vector<string> a(n,""),b(n);
    vector<int> d(n),e(n);
    for(int i=0;i<n;++i) {
        for(int j=0;j<k;++j) {
            cin >> c;
            if(c != '0') {
                a[i] += c;
                if(a[i].size()==1) e[i] = j;
                if(c!= '1') d[i] = a[i].size()-1;
            }
        }
    }
    for(int i=0;i<n;++i) {
        cin >> b[i];
    }
    for(int i=0;i<a.size();++i) {
        int j=0;
        while (j<b.size()) {
            if(a[i].size()==b[j].size() && a[i][d[i]]==b[j][d[i]]) {
                a[i] = b[j];
                b.erase(b.begin()+j);
                break;
            }
            else j++;
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<e[i];++j) cout << '0';
        cout << a[i];
        if(a[i].size()+e[i]<k) {
            for(int j=1;j<=k-e[i]-a[i].size();++j) cout << '0';
        }
        cout << '\n';
    }
}
