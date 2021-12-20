#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    string s;
    cin >> k >> n;
    cin >> s;
    int i=0;
    while(n>0) {
        if(i==s.size()-1) {
            s.erase(s.size()-n);
            break;
        }
        if(s[i]<s[i+1]) {
            s.erase(s.begin() + i);
            if(i!=0) --i;
            --n;
        }
        else ++i;
    }
    cout << s;

}
