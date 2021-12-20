// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
using namespace std;


const int N1 = 2e5+5;
const int N2 = 1e6 + 5;



signed main() {
	fast_cin();
	int a[5];
	for(int i=1;i<=4;++i) cin >> a[i];
	int ans = 1000;
	for(int i=1;i<=4;++i) {
		if(a[i] == 0) continue;
		for(int j=1;j<=4;++j) {
			if(i==j) continue;
			int m1 = a[i]*10 + a[j];
			int pos1=0,pos2=0;
			for(int k=1;k<=4;++k) {
				if(k == i || k == j) continue;
				if(pos1 == 0) pos1 = k;
				else pos2 = k;
			}
			if(a[pos1] != 0) ans = min(ans,abs(m1 - a[pos1]*10 - a[pos2]));
			if(a[pos2] != 0) ans = min(ans,abs(m1 - a[pos2]*10 - a[pos1]));
		}
	}
	cout << ans;
}