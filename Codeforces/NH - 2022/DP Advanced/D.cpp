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
const int MAXN1 = 1e5+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;

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

vi operator+(vi a, const vi &b) {
	a.resize(max(a.size(),b.size()));	
	for(int i=0;i<b.size();++i) {
		a[i] += b[i];
	}
	fix(a);
	return a;
}

vi operator-(vi a, const vi &b) {
	for(int i=0;i<b.size();++i) {
		a[i] -= b[i];
	}
	fix(a);
	return a;
}

vi operator*(const vi &a, const vi &b) {
	vi c(a.size() + b.size()+1);
	for(int i=0;i<a.size();++i) {
		for(int j=0;j<b.size();++j) {
			c[i+j] += a[i]*b[j];
			c[i+j+1] += c[i+j]/10;
			c[i+j] %= 10;
		}
	}
	fix(c);
	return c;
}


vi operator*(vi a, int b) {
	a.resize(a.size() + ins(b) + 1);
	for(int i=0;i<a.size();++i) {
		a[i] *= b;
	}
	fix(a);
	return a;
}

vi operator/(vi a,int b) {
	vi c(a.size());
	int cur = 0,tmp;
	for(int i=c.size()-1;i>=0;--i) {
		tmp = cur*10 + a[i];
		c[i] = tmp/b;
		cur = tmp%b;
	}
	fix(c);
	return c;
}

bool operator<(const vi &a, const vi &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}


bool operator>=(const vi& a, const vi& b) {
	if(a.size() != b.size()) return a.size() > b.size();
	
	for(int i = a.size() - 1; i >= 0; --i) {
		if(a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
	
	return true;
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


int len, depth;
vi k;

vi dp[105][105][105];

vi calc(int pos, int diff, int deg)  {
/*	db(pos);
	db(diff);
	db(deg);
	cerr << "\n";*/
	if(pos == len) {
		return dp[pos][diff][deg] = {(diff == 0 && deg == depth)};
	}
	
	if(sz(dp[pos][diff][deg])) return dp[pos][diff][deg];
	
	vi res;
	
	res = res + calc(pos + 1, diff + 1, max(deg, diff + 1));
	
	if(diff != 0) {
		res = res + calc(pos + 1, diff - 1, max(deg, diff - 1));
	}
	
	return dp[pos][diff][deg] = res;
	
}


signed main() {
	fast_cin();
	
	cin >> len >> depth >> k;
	
	cout << calc(0, 0, 0) << "\n";

	
	vi sum = {0};
	int diff = 1, deg = 1;
	string res = "(";
	for(int pos = 2; pos <= len; ++pos) {
		if(diff != 0 && (sum + dp[pos][diff - 1][deg] >= k)) {
			--diff;
			res += ')';
		}
		
		else {
			if(diff != 0) sum = sum + dp[pos][diff - 1][deg];
			++diff;
			deg = max(deg, diff);
			res += '(';
		}
	}
	
	
	cout << res;
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}