// hihi uyennhi ne :>
#include<bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;

const int mxn = 2e5+5;
const int mod = 1e9+7;
const int inf = 2e18;
const double eps = 1e-9;


int n,m,q;


void maxi(vector< vector<int> > &ans, vector< vector<int> > &b) {
	for(int i=0;i < m;++i) {
		for(int j=0;j <n; ++j) {
			if(ans[i][j] != b[i][j]) {
				//cout << ans[i][j] << " " <<  b[i][j] << "\n";
				if(ans[i][j] < b[i][j]) {
					ans = b;
					//cout << ans[i][j] << " " <<  b[i][j] << "\n";
				}
				return;
			}
		}
	}
}

signed main() {
	fast_cin();
	cin >> m >> n;
	vector< vector<int> > a(n, vector<int>(m)), c(n, vector<int>(m));
	for(int i=0;i<m;++i) {
		for(int j = 0;j < n;++j) {
			cin >> a[j][i];
		}
	}
	vector< vector<int> > b(m, vector<int> (n)), ans(m, vector<int>(n,0));
	for(int i=0;i<m;++i) {
		c = a;
		
		
		for(int j=0;j < n;++j) {
			swap(c[j][i], c[j][0]);
		}
		sort(c.rbegin(),c.rend());
		
		// for(auto x : c) {
			// for(auto ele : x) {
				// cout << ele << " ";
			// }
			// cout << "\n";
		// }
		// cout << "\n";
		
		
		for(int l=0;l<m;++l) {
			for(int j=0;j < n;++j) {
				b[l][j] = c[j][l];
			}
		}
		sort(b.rbegin(),b.rend());
		
		// for(auto x : b) {
			// for(auto ele : x) {
				// cout << ele << " ";
			// }
			// cout << "\n";
		// }
// 		
		// cout << "\n\n";
		
		maxi(ans,b);
	}
	
	// for(auto x : ans) {
		// for(auto ele : x) {
			// cout << ele << " ";
		// }
		// cout << "\n";
	// }
	
	cin >> q;
	for(int i=1;i<=q;++i) {
		int u,v;
		cin >> u >> v;
		cout << ans[u-1][v-1] << "\n";
	}

}