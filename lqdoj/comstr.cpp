#include<bits/stdc++.h>

using namespace std;

int main() {
    string s,a="",x;
    cin >> s;
    stringstream ss;
    int q=1;
    for(int i=0;i<s.size();++i) {
        if(s[i]==s[i+1]) q++;
        else {
            stringstream ss;
            ss << q;
            ss >> x;
            if(q>1) a += x + s[i];
            else a += s[i];
            q = 1;
        }
    }
    cout << a;

}
