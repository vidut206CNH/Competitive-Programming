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
const int MAXN1 = 205;
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

vi conv(int val) {
	vi ans;
	while(val) {
		ans.push_back(val%10);
		val /= 10;
	}
	
	if(sz(ans) == 0) ans.push_back(0);
	return ans;
}


int n;
vi dp[MAXN1][MAXN1];
int a[MAXN1];
int res[MAXN1];


signed main() {
	fast_cin();
	
	cin >> n;
	dp[2*n][0] = conv(1);
	
	for(int pos = 2*n; pos > 0; --pos) {
		for(int val = 0; val <= 2*n; ++val) {
			if(val != 0) {
				dp[pos - 1][val - 1] = dp[pos - 1][val - 1] + dp[pos][val];
			}
			
			dp[pos - 1][val + 1] = dp[pos - 1][val + 1] + dp[pos][val];
		}
	}
	
	cout << dp[0][0]  << "\n";
	int type;
	
	while(cin >> type) {
		if(type == 1) {
			for(int i = 0; i <= 2*n; ++i) {
				cin >> a[i];
			}
			
			res[0] = 0;
			res[1] = 1;
			vi sum = conv(0);
			for(int i = 2; i <= 2*n; ++i) {
				if(a[i] == a[i - 1] + 1 && a[i] != 1) {
					sum = sum + dp[i][a[i - 1] - 1];
				}
			}
			
			cout << sum + conv(1) << "\n";
		}
		
		else {
			vi k;
			cin >> k;
			
			res[0] = 0;
			res[1] = 1;
			vi sum = conv(0);
			for(int i = 2; i <= 2*n; ++i) {
				//cout << sum << " " << i << "\n";
				if(res[i - 1] == 0) {
					res[i] = res[i - 1] + 1;
					continue;
				}
				
				if((sum + dp[i][res[i - 1] - 1] < k)) {
					sum = sum + dp[i][res[i - 1] - 1];
					res[i] = res[i - 1] + 1;
					continue;
				}
				
				else {
					res[i] = res[i - 1] - 1;
				}
			}
			
			for(int i = 0; i <= 2*n; ++i) cout << res[i] << " \n"[i == 2*n];
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}