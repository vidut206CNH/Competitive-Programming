/* 
	link problem: 
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
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 2e18

typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXX = 2e9;
const int MINN = -2e9;
const int nMax = 1e6+5;

int f[50];

int powz(int a,int b) {
	int res = 1;
	while(b) {
		if(b&1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}
int n;
char hexz[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string conv(int m) {
	string s = "";
	while(m) {
		s = hexz[m%16] + s;
		m/=16;
	}
	return s;
}

void solve() {
	cin >> n;
	if(n<=15) {
		cout << hexz[n];
		return;
	}
	int pos,m,q;
	for(int i=0;i<=10;++i) {
		if(f[i] >= n) {
			pos = i-1;
			break;
		}
	}
	n -= f[pos];
	q = n%(pos+1) + (pos+1)*(n%(pos+1)==0);
	n = n/(pos+1) + (n%(pos+1)!=0);
	m = powz(16,pos) + n - 1;
	//cout << m << " " << q;
	cout << conv(m)[q-1];
}


int32_t main() {
	fast_cin();
	int t = 1;
	f[1] = 15;
	for(int i=2;i<=13;++i) {
		f[i] = 15*powz(16,i-1)*i + f[i-1];
		//cout << f[i] << "\n";
	}
	//cin >> t;
	while(t) {
		solve();
		cout << "\n";
		--t;
	}
	return 0;
}
