#include <bits/stdc++.h>

using namespace  std;

string solve(string s) {
    int n = s.size();
    if (s[n-2] == 'A') {
        if ((s[0] == '1') && (s[1] == '2')) {
            s[0] -= 1;
            s[1] -= 2;
        }
    }
    else {
        if ((s[0] == '1') && (s[1] == '2'));
        else {
            s[0] += 1;
            if (s[1]>'7') {
                s[1] -= 8;
                s[0] += 1;
            }
            else s[1] += 2;
        }
    }
    s.erase(n-2);
    return s;
}


int main() {
    string s;
    cin >> s;
    s = solve(s);
    cout << s;
}
