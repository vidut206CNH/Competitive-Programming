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
const int MAXN1 = 5e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

int n;
int a[MAXN1];
pii b[MAXN1];
int minl[MAXN1];
int minr[MAXN1];
int maxl[MAXN1];
int maxr[MAXN1];

stack<int> stmin;
stack<int> stmax;

int bit[MAXN1];


struct var{
	bool type; // 0 1
	int val;
	int pos;
	
	
	bool operator() (const var& A, const var& B) {
		if(A.val != B.val) return A.val > B.val;
		return A.type > B.type;
	}
};

void update(bool d, int pos) {
	if(d) for(;pos > 0; pos -= (pos & -pos)) bit[pos]++;
	else for(;pos <= n + 1; pos += (pos & -pos)) bit[pos]++;
}

int get(bool d, int pos) {
	int res = 0;
	
	if(d) for(;pos <= n + 1; pos += (pos & -pos)) res += bit[pos];
	else for(;pos > 0; pos -= (pos & -pos)) res += bit[pos];
	
	return res;
}

signed main() {
	fast_cin();
	
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = 1; i <= n; ++i) {
		// min
		while(!stmin.empty() && a[stmin.top()] >= a[i]) stmin.pop();
		if(stmin.empty()) minl[i] = 0;
		else minl[i] = stmin.top();
		stmin.push(i);
		
		// max
		while(!stmax.empty() && a[stmax.top()] <= a[i]) stmax.pop();
		if(stmax.empty()) maxl[i] = 0;
		else maxl[i] = stmax.top();
		stmax.push(i);
	
	}
	while(!stmin.empty()) stmin.pop();
	while(!stmax.empty()) stmax.pop();
	
	for(int i = n; i >= 1; --i) {
		// min
		while(!stmin.empty() && a[stmin.top()] >= a[i]) stmin.pop();
		if(stmin.empty()) minr[i] = n + 1;
		else minr[i] = stmin.top();
		stmin.push(i);
		
		// max
		while(!stmax.empty() && a[stmax.top()] <= a[i]) stmax.pop();
		if(stmax.empty()) maxr[i] = n + 1;
		else maxr[i] = stmax.top();
		stmax.push(i);
	}
	
	
	int ans = 0;
	// init
	vector<var> p;
	for(int i = 1; i <= n; ++i) {
		p.push_back({0, i, i});
	}
	
	for(int i = 1; i <= n; ++i) {
		p.push_back({1, minr[i], i});
	}
	
	sort(p.begin(), p.end(), var());
	
	for(auto cur : p) {
		int t = cur.type;
		int val = cur.val;
		int pos = cur.pos;
		
		if(t == 0) {
			int sum = get(false, val) - get(false, maxl[val]);
			ans += sum;
		} else {
			update(false, pos);
		}
	}
	
	p.clear();
	memset(bit, 0, sizeof bit);
	
	for(int i = 1; i <= n; ++i) {
		p.push_back({0, i, i});
	}
	
	for(int i = 1; i <= n; ++i) {
		p.push_back({1, minl[i], i});
	}
	
	sort(p.begin(), p.end(), [&](const var& A, const var& B){
		if(A.val != B.val) return A.val < B.val;
		return A.type < B.type;
	});
	
	
	for(auto cur : p) {
		int t = cur.type;
		int val = cur.val;
		int pos = cur.pos;
		
		if(t == 0) {
			int sum = get(true, val) - get(true, maxr[val]);
			ans += sum;
		} else {
			update(true, pos);
		}
	}
	
	cout << ans - n;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}