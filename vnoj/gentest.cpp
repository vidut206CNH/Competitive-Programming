#include<bits/stdc++.h>

using namespace std;

#define ll long long
void solve() {
    ll n,arr[3],cnt = 0;
    cin >> arr[1] >> arr[2];
    sort(arr, arr+3);
    cout << arr[0] << arr[1] << arr[2];
    // cin >> n;
    // for(int i=0;i<n;i++) {
    //     ll x; cin >> x;
    //     arr[x%3] ++;

    // }
    // ll t = 0;
    // while(!((arr[0] == arr[1]) && (arr[1] == arr[2]))) {
    //     while(arr[t%3] > (n/3)){
    //         --arr[t%3];
    //         ++arr[(t+1)%3];
    //         cnt++;
    //     }
    //     t++;
    //     }
    // cout << cnt << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test;
    cin >> test;
    for(int i = 0; i < test; i ++) {
        solve();
    }
}