#include<iostream>

using namespace std;
typedef long long ll;
int main() {
    ll n,k,ai,cnt=0;
    cin >> n >> k;
    ll arr[k];
    for (ll i=0;i<k;++i) {
        arr[i] = 0;
    }
    for (ll i=0;i<n;++i) {
        cin >> ai;
        arr[ai%k] = 1;
    }
    for (ll i=0;i<k;++i) {
        if (arr[i] == 1) {
            cnt += 1;
        }
    }
    cout << cnt;
}
