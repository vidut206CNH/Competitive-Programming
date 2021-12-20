#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    stringstream ss;
    ss << n;
    ss >> s;
    int t = s.size(),k=n,x,res=0;
    while(res <= n && k>0) {
        x = k%10;
        res += pow(x,t);
        k/=10;
    }
    if(res == n) cout << "YES";
    else cout << "NO";

}
