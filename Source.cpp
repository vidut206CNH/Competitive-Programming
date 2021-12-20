#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

#define ll long long 
#define fl float
#define ld long double

#define fi first
#define se second
#define pb push_back
#define pp_b pop_back

#define MAX 1005
#define pi 3.1415926535
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define vecll vector<ll>
#define pp pair<ll,ll>
#define pvl vector<pair<ll,ll>>
#define xd "\n"

#define FOR(i,a,b) for(ll i = a;i<=b;i++)
#define FOD(i,a,b) for(ll i = a;i>=b;i--)

const long long INF = 2000000000;

// Nguyễn Phongg :))
using namespace std;

queue<pp> h;
bool a[MAX+3][MAX+3];
ll n;

int main() {
	cin >> n;
	FOR(i, 0, MAX - 1)FOR(j, 0, MAX - 1)a[i][j] = 0;
	ll gtx = 0;
	ll gty = 0;
	FOR(i, 1, n) {
		ll u, v;
		cin >> u >> v;
		h.push({u,v});
		gtx = max(gtx, u);
		gty = max(gty, v);
		a[u][v] = 1;
	}
	ll dem = 0;
	while (!h.empty()) {
		dem++;
		pp o = h.front();
		h.pop();
		ll minn = o.first;
		ll maxx = o.fi;
		FOR(i, 0, o.fi) {
			if (a[i][o.se]) {
				minn = i;
				break;
			}
		}
		FOD(i, gtx, o.fi) {
			if (a[i][o.se]) {
				maxx = i;
				break;
			}
		}
		FOR(i, minn, maxx) {
			if (a[i][o.se]) continue;
			else {
				a[i][o.se] = true;
				h.push({ i,o.se });
			}
		}
		ll minx = o.second;
		ll maxy = o.second;
		FOR(i, 0, o.se) {
			if (a[o.fi][i]) {
				minn = i;
				break;
			}
		}
		FOD(i, gty, o.se) {
			if (a[o.fi][i]) {
				maxx = i;
				break;
			}
		}
		FOR(i, minn, maxx) {
			if (a[o.fi][i]) continue;
			else {
				a[o.fi][i] = true;
				h.push({ o.first,i });
			}
		}
	}
	cout << dem;
}