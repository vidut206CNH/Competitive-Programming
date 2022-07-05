/* 
	Author : vidut_206_CNH
*/
#include <bits/stdc++.h>
using namespace std;
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

int n,k;
vi S;

vi C[305][305];
bool ok[305];
int a[305];
int res[305];

void calc_C() {
	C[0][0] = {1};
	
	for(int i = 1; i <= 300; ++i) {
		C[i][0] = {1};
		for(int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

int main() {
	fast_cin();
	calc_C();
	
	cin >> n >> k >> S;
	for(int i = 1; i <= k; ++i) cin >> a[i];
	
	for(int pos = 1; pos <= k; ++pos) {
		for(int val = res[pos - 1] + 1; val <= n; ++val) {
			
			if(ok[val]) continue;
					
			if(C[n - val][k - pos] < S) {
				S = S - C[n - val][k - pos];
			}
			
			else {		
				ok[val] = true;
				res[pos] = val;
				break;
			}
		}
		//cout << S << "\n";
	}
	
	for(int i = 1; i <= k; ++i) cout << res[i] << " \n"[i == k];
	memset(ok, false, sizeof ok);
	
	vi ans = {0};
	for(int pos = 1; pos <= k; ++pos) {
		for(int val = a[pos - 1] + 1; val < a[pos]; ++val) {
			if(ok[val]) continue;
			
			ans = ans + C[n - val][k - pos];		
		}
		
		ok[a[pos]] = true;
		//cout << ans << " ";
	}
	ans = ans + C[0][0];
	
	cout << ans;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}