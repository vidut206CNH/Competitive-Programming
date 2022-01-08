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
#define db(x) cerr << "[" << "Line " << __LINE__ << " -- " << (#x) << " : " << x << "] "

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n,m,k,x;

char a[505];
char b[505][30];
char res[505];

int powr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b&1) ans = ans*a;
		a *= a;
		b /= 2;
	}
	return ans;
}

signed main() {
	fast_cin();
	
	cin >> n >> m >> k >> x;
	cin.ignore();
	
	vector<int> p;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		if(a[i] == '#') {
			p.push_back(i);
		}
	}
	cin.ignore();
	for(int i=1;i <= m;++i) {
		for(int j=1;j<=k;++j) {
			cin >> b[i][j]; 
		}
		cin.ignore();
		sort(b[i] + 1, b[i] + k + 1);
	}
	int pref = 0,start = m, temp = x;
	
	while(temp) {
		temp /= k;
		start--;
	}
	for(int i=1;i<start;++i) {
		res[i] = b[i][1];
	}
	for(int i=max(1LL,start);i<=m;++i) {
		if(i == m) {
			res[i] = b[i][x];
			break;
		}
		for(int j=1;j <= k;++j) {
			if(x <= pref + powr(k, m - i)) {
				res[i] = b[i][j];
				x -= pref;
				pref = 0;
				//db(res[i]);
				break;
			}
			pref += k*(m - i);
		}
	}
	int id = 1;
	for(auto g : p) {
		a[g] = res[id];
		id++;
	}
	for(int i=1;i<=n;++i) {
		cout << a[i];
	}
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}