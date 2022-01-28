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
const int MAXN1 = 3005;
const int base = 1000;
const int inf = 1e18;


int n;
int mark[MAXN1][MAXN1];

int minR[MAXN1], maxR[MAXN1];
int minC[MAXN1], maxC[MAXN1];

queue<pii > q;

signed main() {
	fast_cin();
	
	
	for(int i=0;i<=2000;++i) {
		minR[i] = MAXN1;
		minC[i] = MAXN1;
	}

	memset(maxR, -1, sizeof maxR);
	memset(maxC, -1, sizeof maxC);
	
	cin >> n;
	for(int i=1;i<=n;++i) {
		int r,c;
		cin >> r >> c;
		r += base;
		c += base;
		mark[r][c] = true;
		q.push({r, c});
	}
	
	int res = 0;
	
	while(!q.empty()) {
		pii p = q.front();
		
		q.pop();
		int row = p.fi;
		int col = p.se;
/*		db(row);
		db(col);
		db(minR[row]);
		db(maxR[row]);
		db(maxR[col]);
		db(maxC[col]);
		cerr << "\n";*/
		
		if(maxR[row] != -1) {
			for(int i= col + 1; i < minR[row]; ++i) {
				if(mark[row][i] == false) {
					mark[row][i] = true;
					q.push({row,i});
				}
			}
			for(int i=col - 1; i > maxR[row]; --i) {
				if(mark[row][i] == false) {
					mark[row][i] = true;
					q.push({row, i});
				}
			}
		}
		
		if(maxC[col] != -1) {
			for(int i=row + 1; i < minC[col]; ++i) {
				if(mark[i][col] == false) {
					mark[i][col] = true;
					q.push({i, col});
				}
			}
			
			for(int i=row - 1; i > maxC[col]; --i) {
				
				if(mark[i][col] == false) {
					mark[i][col] = true;
					q.push({i, col});
				}
			}
			
		}
		
		minR[row] = min(minR[row], col);
		maxR[row] = max(maxR[row], col);
		minC[col] = min(minC[col], row);
		maxC[col] = max(maxC[col], row);
		
	}
	
	for(int row=0;row<=2000;++row) {
		if(maxR[row] == -1) continue;
		res += (maxR[row] - minR[row] + 1);
	}
	
	cout << res;
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}