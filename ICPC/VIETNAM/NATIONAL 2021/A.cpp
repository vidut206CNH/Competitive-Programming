/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) (a/gcd(a,b)*b)
#define sz(x) (int)(x.size())
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(x) cerr << "[" << "Line " << __LINE__ << " : " << (#x) << " = " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN2];
vector<int> color[MAXN1];
int res[MAXN2];


// xn la max  sum = n^2 <= xn*n < n*n

bool comp(const vector<int>& A, const vector<int>& B) {
	return sz(A) < sz(B);
}


signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n*n; ++i) {
		cin >> a[i];
		color[a[i]].push_back(i);
	}
	
	for(int id = 1; id <= n; ++id) {
/*		db(sz(pre));
		cerr << "\n";*/
		sort(color + 1, color + n + 2, comp);
		int left = 1;
		while(sz(color[left]) == 0) left++;
		int sum = sz(color[n + 1]) + sz(color[left]);
		
		if(sum < n) {
			cout << "NO";
			exit(0);
		}
		
		int cnt = 0;
		vector<int> tmp1;
		for(auto x : color[left]) {
			if(cnt == n) {
				tmp1.push_back(x);
				continue;
			}
			res[x] = id;
			cnt++;
		}
		
		color[left] = tmp1;
		
		vector<int> tmp;
		
		for(auto x : color[n + 1]) {
			if(cnt == n) {
				tmp.push_back(x);
				continue;
			}
			res[x] = id;
			cnt++;
		}
		
		color[n + 1] = tmp;
		
	}
	cout << "YES\n";
	for(int i = 1; i <= n*n; ++i) cout << res[i] << " ";
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}