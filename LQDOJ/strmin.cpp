#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    string s,str="";
    cin >> k >> s;
    int n = s.size();
    int lo = 0;
    while(k) {
        int Min=10;
        char Minc;
        int i = lo;
        while(i<=n-k) {
            int x = (int)s[i] - 48;
            if(Min>x) {
                Min = x;
                Minc = s[i];
                lo = i+1;
            }
            ++i;
        }
        str += Minc;
        --k;
    }
    cout << str;

}
