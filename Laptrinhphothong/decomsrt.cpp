#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i=0;
    while(i<s.size()) {
        long long n=0,x;
        while(s[i]<'a'&&i<s.size()-1) {
            x = (int)s[i] - 48;
            n *= 10;
            n += x;
            ++i;
        }
        for(int j=0;j<n;++j) {
            cout << s[i];
        }
        if(n==0) cout << s[i];
        ++i;
    }

}
