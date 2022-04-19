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

bool operator >= (const vi& A, const vi& B) {
	if(sz(A) != sz(B)) return sz(A) > sz(B);
	for(int i = sz(A) - 1; i >= 0; --i) {
		if(A[i] != B[i]) return A[i] > B[i];
	}
	
	return true;
}

int n;
vi k;
vi dp[1005][1005][2];
bool choose[1005];


vi calc(int pos, int less, bool dir) {
	if(pos == n + 1) {
		return dp[pos][less][dir] = {(less == 0)};
	}
	
	if(sz(dp[pos][less][dir])) return dp[pos][less][dir];
	vi res;
	
	if(dir == false) {
		for(int val = less + 1;val <= n - pos + 1; ++val) {
			res = res + calc(pos + 1, val - 1, !dir);		
		}
	}
	
	else {
		for(int val = 1; val <= less; ++val) {
			res = res + calc(pos + 1, val - 1, !dir);
		}
	}
	
	return dp[pos][less][dir] = res;
}

int res[1005];

signed main() {
	fast_cin();
	
	
	while(cin >> n) {
		cin >> k;
		
		for(int i = 1; i <= n; ++i) res[i] = 0;
		for(int i = 1; i <= n; ++i) choose[i] = 0;
		
		for(int i = 0; i <= n + 1; ++i) {
			for(int j = 0; j <= n + 1; ++j) {
				for(int dir = 0; dir < 2; ++dir) {
					dp[i][j][dir].clear();
				}
			}
		}
		
		vi rem;
		bool D = 0;
		
		for(int val = 1; val <= n; ++val) {
			for(int dir = 1; dir >= 0; --dir) {
				if(rem + calc(2, val - 1, dir) >= k) {
					res[1] = val;
					choose[val] = true;
					D = dir;
					break;
				}
				rem = rem + calc(2, val - 1, dir);
			}
			
			if(res[1] != 0) break;
		}
		
		for(int pos = 2; pos <= n; ++pos) {
			if(D) {
				int less = 0;
				
				for(int val = 1; val < res[pos - 1]; ++val) {
					if(choose[val]) continue;
					if(rem + calc(pos + 1, less, !D) >= k) {
						choose[val] = true;
						res[pos] = val;
						D ^= 1;
						break;
					}
					
					less++;
					rem = rem + calc(pos + 1, less - 1, !D);
				}
				
			}
			
			else {
				int less = 0;
				for(int val = 1; val <= n; ++val) {
					if(choose[val]) continue;
					if(val <= res[pos - 1]) {
						less++;
						continue;
					}
					
					if(rem + calc(pos + 1, less, !D) >= k) {
						choose[val] = true;
						res[pos] = val;
						D ^= 1;
						break;
					}
					
					less++;
					rem = rem + calc(pos + 1, less - 1, !D);
					
				}
			}
		}
		
		for(int i = 1; i <= n; ++i) {
			cout << res[i] << " \n"[i == n];
		}
	}
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}