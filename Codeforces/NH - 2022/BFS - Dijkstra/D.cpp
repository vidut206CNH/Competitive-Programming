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
const int base =  1e6;
const int MAXN2 = 2e6+5;
const int inf = 1e18;

vector<int> v(3), a(3), b(3);
queue< vector<int> > q;


int dist[3][3][3][MAXN2];

int sumall = 0;



vector<int> calc(const vector<int> & A) {
	vector<int> res(4, 0);
	vector<int> g;
	if(A == a) return vector<int>(4, 2);
	
	for(int i = 0; i < 3; ++i) {
		if(A[i] == 0) {
			res[i] = 0;
		}
		else if(A[i] == v[i]) {
			res[i] = 1;
		}
		else {
			res[i] = 2;
			g.push_back(A[i]);
		}
	}
	if(sz(g) == 0) res[3] = base;
	else if(sz(g) == 1) res[3] = g[0] + base;
	else res[3] = (g[0] - g[1]) + base;
	return res;
}


void solve(const vector<int>& cur, int idx, int idy, int cost) {
	if(cur[idx] == 0) return;
	if(cur[idy] == v[idy]) return;
	int val = min(cur[idx], v[idy] - cur[idy]);
	
	vector<int> d = cur;
	d[idx] -= val;
	d[idy] += val;
	vector<int> state = calc(d);
	
	
	if(dist[state[0]][state[1]][state[2]][state[3]] == -1) {
		dist[state[0]][state[1]][state[2]][state[3]] = cost + 1;
		q.push(d);
	}
	
}


signed main() {
	fast_cin();
	
	for(int i = 0; i < 3; ++i) cin >> v[i];
	for(int i = 0; i < 3; ++i) cin >> a[i];
	for(int i = 0; i < 3; ++i) cin >> b[i];
	
	
	

	for(int i = 0; i < 3; ++i) {
		for(int j = i + 1; j < 3; ++j) {
			if(v[i] > v[j]) {
				swap(v[i], v[j]);
				swap(a[i], a[j]);
			}
		}
	}
	
	sort(b.begin(), b.end());
	vector<int> tmp = a;
	sort(tmp.begin(), tmp.end());
	if(b == tmp) {
		cout << 0;
		exit(0);
	}
	
	int sum = 0;
	bool ok = true;
	for(int i = 0; i < 3; ++i) {
		sumall += a[i];
		sum += (a[i] - b[i]);
		ok &= (b[i] <= v[i]);
	}
	if(sum || !ok) {
		cout << -1;
		exit(0);
	}
	
	
	// BFS
	
	memset(dist, -1, sizeof dist);
	
	dist[2][2][2][2] = 0;
	
	q.push(a);

	
	while(!q.empty()) {
		vector<int> cur = q.front();
		q.pop();
		
		

		
		vector<int> state = calc(cur);
		int cost = dist[state[0]][state[1]][state[2]][state[3]];
		
		
		// check
		int s1 = state[0];
		int s2 = state[1];
		int s3 = state[2];
		int diff = state[3];

		int sumt = 0, cnt = 0;
		vector<int> c;
		int diff1 = diff - base;
		
		if(s1 == 0) c.push_back(0);
		if(s2 == 0) c.push_back(0);
		if(s3 == 0) c.push_back(0);
		
		if(s1 == 1) {
			c.push_back(v[0]);
			sumt += v[0];
		}
		if(s2 == 1) {
			c.push_back(v[1]);
			sumt += v[1];
		}
		if(s3 == 1) {
			c.push_back(v[2]);
			sumt += v[2];
		}
		
		
		if(s1 == 2) cnt++;
		if(s2 == 2) cnt++;
		if(s3 == 2) cnt++;
		
		if(cnt == 1) c.push_back(diff1);
		else if(cnt == 2) {
			c.push_back((sumall - sumt + diff1)/2);
			c.push_back((sumall - sumt - diff1)/2);
		}
		
		sort(c.begin(), c.end());
		if(c == b) {
			cout << cost;
			exit(0);
		}
		

		solve(cur, 0, 1, cost);
		solve(cur, 1, 0, cost);
		solve(cur, 0, 2, cost);
		solve(cur, 2, 0, cost);
		solve(cur, 1, 2, cost);
		solve(cur, 2, 1, cost);

	}
	
	cout << -1;

	


	
	
	#ifndef LOCAL_DEFINE
    cerr << "\nTime elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n ";
    #endif
	
	return 0;
}