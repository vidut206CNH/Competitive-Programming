#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = "";
    vector<string> vec;
    int a = s.size();
    for (int i=0;i<a;++i) {
        if (islower(s[i])) {
            s1 = s1 + s[i];
            if (i == a-1) vec.push_back(s1);
        }
        else {
            vec.push_back(s1);
            s1 = "";
            s1 += s[i];
        }
    }
    cout << vec.size();
}
