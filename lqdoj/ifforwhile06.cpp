#include<bits/stdc++.h>

using namespace std;

int main() {
    double a,b,c,res;
    cin >> a >> b >> c;
    res = (2*a+2*b+c)/5;
    if(res >= 8) cout << "gioi";
    else if (res >= 6.5) cout << "kha banh";
    else if (res >= 5) cout << "trung binh";
    else cout << "yeu";
}
