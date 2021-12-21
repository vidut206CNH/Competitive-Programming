#include<bits/stdc++.h>

using namespace std;

void addstring(string &a,string &b) {
    string res = "";
    if(a.size()<b.size()) {
        string temp = b;
        b = a;
        a = temp;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sa = a.size(),sb = b.size();
    int carry = 0;
    for(int i=0;i<b.size();++i) {
        int x = ((int)a[i] - 48) + ((int)b[i] - 48) + carry;
        carry  = x/10;
        x %= 10;
        res += (x + 48);
    }
    for(int i=b.size();i<a.size();++i) {
        int x = ((int)a[i] - 48) + carry;
        carry = x/10;
        res += x%10 + 48;
    }
    if(carry) res += '1';
    reverse(res.begin(),res.end());
    cout << res;
}


int main() {
    string s1,s2;
    cin >> s1 >> s2;
    addstring(s1,s2);
}
