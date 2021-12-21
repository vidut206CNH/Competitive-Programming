#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
	ll a,sum=0,cnt=0;
    cin >> a;
    while(a!=0) {
        sum += a%10;
        a /= 10;
        cnt += 1;
    }
    cout << cnt << "\n" << sum;
}
