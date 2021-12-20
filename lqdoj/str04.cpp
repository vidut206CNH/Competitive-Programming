#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    string st = "";
    vector<char> vec;
    getline(cin, s);
    for (int i=0;i<s.size();++i) {
        if ((s[i]== ' ') && (s[i] == s[i+1])) continue;
        else st = st + s[i];
    }
    cout << st;
}
