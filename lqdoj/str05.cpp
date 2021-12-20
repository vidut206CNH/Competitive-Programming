#include<bits/stdc++.h>

using namespace std;

char slt(char a) {
    if (islower(a)) return toupper(a);

    else return tolower(a);
}



int main() {
    string s;
    getline(cin, s);
    for (int i=0;i<s.size();++i) {
        cout << slt(s[i]);
    }
}
