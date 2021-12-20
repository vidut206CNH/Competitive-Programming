#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}


bool sortc(vector<ll> a, vector<ll> b) {
    if (a[0]*a[1] < 0 && b[0]*b[1] > 0) return 1;
    if (b[0]*b[1] < 0 && a[0]*a[1] > 0) return 0;
    else {
        ll ta = a[0], tb = b[0];
        if (b[1] < 0) {
            b[1] *= -1;
            b[0] *= -1;
        }
        if (a[1] < 0) {
            a[1] *= -1;
            a[0] *= -1;
        }
        ll lcmm = lcm(a[1], b[1]);
        ll ra = a[0] * (lcmm / a[1]);
        ll rb = b[0] * (lcmm / b[1]);
        if (ra == rb) return (ta < tb);
        else return (ra < rb);
    }

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector< vector<ll> > frac(n);
    for (int i = 0; i < n; ++i) {
        frac[i].resize(2);
        cin >> frac[i][0];
    }
    for (int i = 0; i < n; ++i) {
        cin >> frac[i][1];
    }
    sort(frac.begin(), frac.end(), sortc);
    for (int i = 0; i < n; ++i) {
        cout << frac[i][0] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << frac[i][1] << ' ';
    }



}
