#include<bits/stdc++.h>

using namespace std;

int main() {
    int cnt=0,a;
    string str;
    getline(cin, str);
    a = str.size();
    for (int i=0;i<a;++i) {
        if (str[i] == ' ') cnt = cnt + 1;
    }
    cout << cnt;


}
