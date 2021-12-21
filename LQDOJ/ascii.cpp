#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s;
    while(s.size()>0) {
        if(s[0] == '9') {
            n = ((int)(s[1]) - 48);
            n += 90;
            s.erase(0,2);
        }
        else {
            n = ((int)(s[2]) - 48);
            n += ((int)(s[1])-48)*10;
            n += 100;
            s.erase(0,3);
        }
        cout << (char)n;
    }
}
