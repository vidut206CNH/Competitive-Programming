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

int t;
bool ok[3][3];
int board[3][3];

signed main() {
	fast_cin();
	
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		memset(board, -1, sizeof board);
		memset(ok, 0, sizeof ok);
		
		s.erase(s.begin());
		
		while(s.size() < 7) s = '0' + s;
		cerr << s.size();
		reverse(s.begin(),s.end());
		
		for(int pos = 0; pos <= 3; pos += 3) {
			int row = 0;
			for(int d = pos; d < pos + 3; ++d) {
				int val = s[d] - '0';
				if(pos%2 == 0) {
					for(int bit = 0; bit < 3;++bit) {
						if(val >> bit & 1) ok[row][bit] = 1;		
					}
				}
				else {
					for(int bit = 0;bit < 3;++bit) {
						if(val >> bit & 1) board[row][bit] = 1;
					}
				}
				row++;
			}
		}
		
		for(int row=0;row < 3;++row) {
			for(int col=0; col < 3; ++col) {
				if(ok[row][col] && board[row][col] == -1) {
					board[row][col] = 0;
				}
				
			}
		}
		
		
		bool turn = (s.back() - '0');
		int win = -1, awin = -1;
		// vertical
		
		for(int col=0;col < 3;++col) {
			int countX = 0;
			int countO = 0;
			bool empt = 0;
			for(int row=0;row < 3; ++row) {
				if(board[row][col] == -1) empt = true;
				countX += (board[row][col] == 1);
				countO += (board[row][col] == 0);
			}
			if(countX == 3) win = 1;
			if(countO == 3) win = 0;
			if(turn && empt) countX++;
			if(!turn && empt) countO++;
			if(countX == 3) awin = 1;
			if(countO == 3) awin = 0;
		}
		
		//horizonal
		
		for(int row = 0;row < 3;++row) {
			int countX = 0;
			int countO = 0;
			bool empt = 0;
			for(int col = 0; col < 3; ++col) {
				if(board[row][col] == -1) empt = true;
				countX += (board[row][col] == 1);
				countO += (board[row][col] == 0);
			}
			
			if(countX == 3) win = 1;
			if(countO == 3) win = 0;
			
			if(turn && empt) countX++;
			if(!turn && empt) countO++;
			
			if(countX == 3) awin = 1;
			if(countO == 3) awin = 0;
			
		}
		
		for(int d = 0;d < 2;++d) {
			int countX = 0;
			int countO = 0;
			bool empt = 0;
			if(d == 0) {
				for(int pos = 0;pos < 3;++pos) {
					if(board[pos][pos] == -1) empt = 1;
					countX += (board[pos][pos] == 1);
					countO += (board[pos][pos] == 0);
				}
				if(countX == 3) win = 1;
				if(countO == 3) win = 0;
				if(turn && empt) countX++;
				if(!turn && empt) countO++;
				if(countX == 3) awin = 1;
				if(countO == 3) awin = 0;
			}
			else {
				for(int pos = 0;pos < 3;++pos) {
					if(board[pos][2 - pos] == -1) empt = 1;
					countX += (board[pos][2 - pos] == 1);
					countO += (board[pos][2 - pos] == 0);
				}
				if(countX == 3) win = 1;
				if(countO == 3) win = 0;
				if(turn && empt) countX++;
				if(!turn && empt) countO++;
				if(countX == 3) awin = 1;
				if(countO == 3) awin = 0;
			}
		}
		if(win != -1) {
			cout << (win == 1 ? "X wins\n" : "O wins\n");
		}
		else {
			bool badall = 1;
			for(int row=0;row<3;++row) {
				for(int col=0;col < 3;++col) {
					badall &= (board[row][col] != -1);
				}
			}
			if(badall) cout << "Cat's\n";
			else cout << "In progress\n";
		}
		
	}	
	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}