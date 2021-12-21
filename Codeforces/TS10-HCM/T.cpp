#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m,n,cnt=0;
	cin >> m >> n;
	set<int> se;
	vector<int> ve;
	int a[m+1][n+1];
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
			int t = se.size();
			se.insert(a[i][j]);
			if(se.size() != t) ve.push_back(a[i][j]);
		}
	}
	sort(ve.begin(),ve.end());
	int mi,ni;
	cin >> mi >> ni;
	auto it = lower_bound(ve.begin(),ve.end(),a[mi][ni]);
	cout << (ve.end()-it-1);
}