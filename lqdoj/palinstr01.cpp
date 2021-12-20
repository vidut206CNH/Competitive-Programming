#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<string> vec;
    while(cin >> s) {
        int a = s.size(),cnt=0;
        for(int i=a/2-1;i>=0;--i) {
            if(s[i] != s[a-i-1]) cnt +=1;
            if(cnt>2) {
                cout << "NO";
                break;
            }
            if(i==0) cout << "YES";
        }
        cout << '\n';
    }

}
