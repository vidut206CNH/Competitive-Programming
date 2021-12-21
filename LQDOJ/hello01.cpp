#include<bits/stdc++.h>

using namespace std;
void solve() {
    string str,s = "hello";
    cin >> str;
    int i=0;
    while(i<str.size()&& s != "") {
        if(str[i]==s[0]) s.erase(s.begin());
        ++i;
    }
    if(s=="") cout << "YES";
    else cout << "NO";
}

int main() {
    int n;
    cin >> n;
    while(n) {
        solve();
        cout << '\n';
        --n;
    }


}
