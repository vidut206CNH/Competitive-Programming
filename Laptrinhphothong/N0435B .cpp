#include<bits/stdc++.h>
#include<sstream>
#define ll long long
using namespace std;
ll a,sum=1;
bool check ( ll a ){
    ll n = sqrt(a);
    if ( n*n==a ) return 1;
    else return 0;
}
int main(){
    string st;
    ll x;
    ll i = 0;
    getline(cin,st);
    stringstream ss(st);
    while(ss >> x) {
        if (check(x)==1) {
            cout << x;
            i += 1;
            break;
        }
    }
    if (i == 0) {
        cout << -1;
    }

}
