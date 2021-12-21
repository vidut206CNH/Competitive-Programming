#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,cnt=0;
    cin >> n;
    string s;
    while(n) {
        cin >> s;
        if(s[1]=='+') cnt++;
        else cnt--;
        --n;
    }
    cout << cnt;
}
