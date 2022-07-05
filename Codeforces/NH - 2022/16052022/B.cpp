#include <bits/stdc++.h>

#define int int64_t 
#define ll long long
#define fi first
#define se second

#define vii vector<int>
#define sz(s) int(s.size())
#define all(v) v.begin(), v.end()

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN1 = 1e6 + 5;
const int MaxN2 = 1e5 + 5;

using namespace std;

struct triple{
    string d, e, f;
} c[MaxN2];

int x, y, g, cnt = 0;
pair<string, string> a[MaxN2], b[MaxN2];
map<string, int> mp1;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> x;
    for(int i = 1; i <= x; i++){
        cin >> a[i].fi >> a[i].se;
    }
    cin >> y;
    for(int i = 1; i <= y; i++){
        cin >> b[i].fi >> b[i].se;
    }
    cin >> g;
    for(int i = 1; i <= g; i++){
        cin >> c[i].d >> c[i].e >> c[i].f;
        mp1[c[i].d] = mp1[c[i].e] = mp1[c[i].f] = i;
    }
    for(int i = 1; i <= x; i++){
        if(mp1[a[i].fi] != mp1[a[i].se]){
            cnt++;
            // cout << i << '\n';
        }
    }
    for(int i = 1; i <= y; i++){
        if(mp1[b[i].fi] == mp1[b[i].se]){
            cnt++;
            // cout << i << '\n';
        }
    }
    cout << cnt;
    
    return 0;
}