#include<bits/stdc++.h>

#define int long long


using namespace std;
const int MX = 105;


int n,k;
int a[MX],f[MX];
int s[MX];


void solve() {
  
  cin >> n >> k;
  for(int i=1;i<=n;++i) {
    cin >> a[i];
    f[i] = f[i-1] + a[i];
  }
  int  res = 0;
  for(int i=2;i<=n;++i) {
    int d = max(0LL, 100*a[i] - k*f[i-1]);
    res = max(res,0LL +  d/k + (d%k != 0));
  }

  cout << res << "\n";


}

signed main() {

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  

  return 0;
}
