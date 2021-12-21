#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    string sr = s;
    reverse(s.begin(), s.end());
    if (s == sr) cout << "YES";
    else cout << "NO";
}
