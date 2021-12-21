#include<bits/stdc++.h>

using namespace std;

void solve(char n,int k) {
    k = k%26;
    char res = n;
    if(res>=97 && res<=122) {
        if(res+k>122) res -= (26-k);
        else res += k;
    }
    else if (res>=65 && res <= 90) {
        if(res+k>90) res -= (26-k);
        else res += k;
    }
    cout << res;

}

int main() {
    int n,k;
    string s;
    cin >> n >> s >>  k;
    for(int i=0;i<n;++i) {
        solve(s[i],k);
    }

}
