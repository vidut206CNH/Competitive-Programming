#include<bits/stdc++.h>

using namespace std;

int main() {
    long long b,res=1,a;
    string s;
    cin>>s>>b;
    long long t= s.size();
    a = ((long long)s[t-1] - 48);
    while(b) {
        if (b%2==1) {
            res = ((res%10)*(a%10))%10;
        }
        a = ((a%10)*(a%10))%10;
        b /= 2;
    }
    cout << res%10;
}
