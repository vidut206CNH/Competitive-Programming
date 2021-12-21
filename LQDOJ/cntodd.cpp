#include<bits/stdc++.h>

using namespace std;

int main() {
    int cnt=0;
    string str;
    getline(cin, str);
    for (int i=0;i<str.size();++i) {
        if ((int)str[i]%2 != 0) cnt = cnt +1;
    }
    cout << cnt;
}
