// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;


const int N1 = 2e5+5;
const int N2 = 1e6 + 5;

int n;

signed main() {
	fast_cin();
	cin >> n;
	int ans = 0;
	int m = n/3;
	ans += (n-m)*m;
	ans += (m+m*(m-1)/2);
	cout << ans;
}