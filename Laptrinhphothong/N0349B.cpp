#include<bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if(a%2==0) a += 1;
    if(b%2==0) b -= 1;
    cout << (a+b)*((b-a)/2+1)/2;

}
