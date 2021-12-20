#include<bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;

void solve(string s) {
    string s1;
    cin >> s1;
    int i=0;
    while(s.size()!= 0 && i<s1.size() && i<= (s1.size()-s.size())) {
        if(s1[i]==s[0]) s.erase(s.begin());
        ++i;
    }
    if(s.size()==0) cout << "YES";
    else cout << "NO";
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    string s;
    cin >>s;
    while(n) {
        solve(s);
        --n;
    }
}
