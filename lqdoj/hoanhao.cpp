#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i=0;i<s.size()-1;++i) {
        if (s[i]== s[i+1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
