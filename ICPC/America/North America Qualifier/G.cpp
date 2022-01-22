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

int lim, n;
int a[MAXN1];

signed main() {
	fast_cin();
	
	cin >> lim >> n;
	
	for(int i=1;i<=n;++i) {
		cin >> a[i];
	}	
	
	int l=1,r=2,last = 1;
	vector<string> error,correct;
	if(a[l] != 1) {
		if(a[l] == 2) correct.push_back(to_string(1));
		else correct.push_back(to_string(1) + '-' + to_string(a[l] - 1));
	}
	while(r <= n) {
		if(r == n) {
			if(a[r] - a[l] != 1) {
				if(a[last] == a[l]) {
					error.push_back(to_string(a[last]));
				}
				else error.push_back(to_string(a[last]) + '-' + to_string(a[l]));
				error.push_back(to_string(a[r]));	
				int lc = a[l] + 1;
				int rc = a[r] - 1;
				if(lc == rc) {
					correct.push_back(to_string(lc));
				}
				else correct.push_back(to_string(lc) + '-' + to_string(rc));
			}
			
			else error.push_back(to_string(a[last]) + '-' + to_string(a[r]));
		}
		else if(a[r] - a[l] == 1) {
			++l;
		}
		else {
			if(last == l) {
				error.push_back(to_string(a[l]));
			} else {
				error.push_back(to_string(a[last]) + '-' + to_string(a[l]));
			}
			int lc = a[l] + 1;
			int rc = a[r] - 1;
			if(lc == rc) {
				correct.push_back(to_string(lc));
			}
			else correct.push_back(to_string(lc) + '-' + to_string(rc));
			++l;
			last = l;
		}
		++r;
	}
	
	if(a[--r] != lim) {
		if(a[r] == lim - 1) correct.push_back(to_string(lim));
		else correct.push_back(to_string(a[r] + 1) + '-' + to_string(lim));
	}
	
	cout << "Errors: ";
	if(error.size() == 1) cout << error.back() << "\n";
	else {
		for(int i=0;i<error.size();++i) {
			cout << error[i];
			if(i == sz(error) - 2) {
				cout << " and ";
			}
			else if(i == sz(error) - 1) cout << "\n";
			else cout << ", ";
		}
	}
	
	cout << "Correct: ";
	if(correct.size() == 1) cout << correct.back() << "\n";
	else {
		for(int i=0;i<correct.size();++i) {
			cout << correct[i];
			if(i == sz(correct) - 2) {
				cout << " and ";
			}
			else if(i == sz(correct) - 1) cout << "\n";
			else cout << ", ";
		}
	}
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}