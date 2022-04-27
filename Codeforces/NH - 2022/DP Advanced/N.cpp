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
const int MAXN1 = 5e3+5;
const int MAXN2 = 1e6+5;
const int inf = 1e18;


int n;
char s[MAXN1];
int f[MAXN1];
int p[MAXN1];
// 0 ~ -1
// 1 ~ 0
// 2 ~ +1

int prefix_pos[3][MAXN1];
int sufix_pos[3][MAXN1];


signed main() {
	fast_cin();
	
	memset(prefix_pos, -1, sizeof prefix_pos);
	memset(sufix_pos, -1, sizeof sufix_pos);
	
	
	cin >> n;
	int cnt_zero = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		f[i] = f[i - 1];
		if(s[i] == '1') f[i]++;
		else if(s[i] == '2') f[i]--;
		
		cnt_zero += (s[i] == '0');
		
		p[i] = i - cnt_zero;
	}
	
	for(int i = 1; i <= n; ++i) {
		prefix_pos[0][i] = (f[i] < 0 ? i : prefix_pos[0][i - 1]);
		prefix_pos[1][i] = (f[i] == 0 ? i : prefix_pos[1][i - 1]);
		prefix_pos[2][i] = (f[i] > 0 ? i : prefix_pos[2][i - 1]);
		db(prefix_pos[0][i]);
		db(prefix_pos[1][i]);
		db(prefix_pos[2][i]);
		cerr << "\n";
	}
	
	for(int i = n; i >= 1; --i) {
		sufix_pos[0][i] = (f[i] < 0 ? i : sufix_pos[0][i + 1]);
		sufix_pos[1][i] = (f[i] == 0 ? i : sufix_pos[1][i + 1]);
		sufix_pos[2][i] = (f[i] > 0 ? i : sufix_pos[2][i + 1]);  
	}
	
	
	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}