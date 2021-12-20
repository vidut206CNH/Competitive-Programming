#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,l,dif=0;
	cin >> n >> l;
	vector<long long> a(n);
	for(int i=0;i<n;++i) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<n;++i) {
		if(i==0) dif = max(dif,(a[i]-0)*2);
		if(i==n-1) {
			dif = max(dif,(l-a[i])*2);
			break;
		}
		dif = max(dif,a[i+1]-a[i]);
	}
	cout << fixed << setprecision(2) << (double)dif/2;
}