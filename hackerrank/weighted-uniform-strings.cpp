#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<bool> a(10000001,false);
    int y,x,cnt=1;
    for(int i=0;i<s.size();++i) {
        x = ((int)s[i]-96);
        if(s[i]==s[i-1]&&i>0) {
            cnt++;
        }
        else cnt=1;
        a[cnt*x] = true;
    }
    while(q) {
        cin >> y;
        if(a[y]==1) cout << "Yes";
        else cout << "No";
        cout <<'\n';
        --q;
    }
}
