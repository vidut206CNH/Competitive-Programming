/* 
	link problem: https://oj.vnoi.info/problem/haoi10_blink
	Author : vidut_206_CNH
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define fast_cin() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;
bool chk[nMax+1];
int n, f[nMax+1],cnt,ans=1,x;
vector<int> pri;
int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void sieve() {
	for(int i=2;i*i<=nMax;++i) {
		if(!chk[i]) {
			for(int j=i*i;j<=nMax;j+=i) chk[j] = 1;
		}
	}
	for(int i=2;i<=nMax;++i) {
		if(!chk[i]) pri.pb(i);
	}
}

typedef vector<int> vi;
int ins(int b) {
	if(b==0) return 1;
	int c = 0;
	while(b) {
		b/=10;
		c++;
	}
	return c;
}

void fix(vi &a) {
	int cur = 0,tmp;
	a.pb(0);
	for(int i=0;i<a.size()-1;++i) {
		a[i + 1] += a[i]/10;
        a[i] %= 10;
        if (a[i] < 0) {
            a[i] += 10;
            a[i + 1]--;
        }
	}
	while(a.size() > 1 && a.back()==0) a.pop_back();
}



vi operator*(vi a, int b) {
	a.resize(a.size() + ins(b) + 1);
	for(int i=0;i<a.size();++i) {
		a[i] *= b;
	}
	fix(a);
	return a;
}


istream &operator>>(istream &cin,vi &a) {
	string s;
	cin >> s;
	a.clear();
	for(int i=s.size()-1;i>=0;--i) {
		a.pb(s[i] - '0');
	}
	fix(a);
	return cin;
}

ostream &operator<<(ostream &cout,const vi &a) {
	for(int i=a.size()-1;i>=0;--i) {
		cout << a[i];
	}
	return cout;
}

void solve() {
	sieve();
	cin >> n;
	vi ans = {1};
	for(int i=1;i<=n;++i) {
		cin >> x;
		for(auto t : pri) {
			if(t*t > x) break;
			if(x%t==0) {
				cnt = 0;
				while(x%t==0) {
					x/= t;
					cnt++;
				}
				f[t] = max(f[t],cnt);
			}
		}
		if(x > 1) f[x] = max(f[x],1LL);
	}
	for(auto t : pri) {
		ans = ans*powz(t,f[t]);
	}
	cout << ans;
}


int32_t main() {
	fast_cin();
	int t = 1;
	//cin >> t;
	while(t) {
		solve();
		cout << '\n';
		--t;
	}
	return 0;
}