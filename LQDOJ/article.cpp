#include<bits/stdc++.h>

using namespace std;

int main() {
    string s = "aeiou";
    char a;
    cin >> a;
    for(int i=0;i<s.size();++i) {
        if(a==s[i]) {
            cout << "an";
            return 0;
        }
    }
    cout << 'a';

}
