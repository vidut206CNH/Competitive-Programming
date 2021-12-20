#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    long long x;
    while(ss >> x) {
        if (x == 2004) {
            cout << 2004;
            return 0;
        }
    }
    cout << -1;
}
