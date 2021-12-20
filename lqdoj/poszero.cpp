#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for(int i=s.size()-1;i>0;--i) {
        if(s[i] == '0') {
            cout << i+1;
            return 0;
        }
    }
}
