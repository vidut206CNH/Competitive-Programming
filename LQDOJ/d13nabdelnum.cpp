#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

int checkv(vector<ll> a) {
    int n = a.size();
    for (int i=a.size()-1;i>0;--i) {
        for (int j=i-1;j>=0;--j) {
            if (a.at(i)%a.at(j) != 0) {
                a.erase(a.begin() + j);
                --i;
            }
        }
    }
    return n-a.size();
}

int main() {
    int N;
    ll a;
    cin >> N;
    vector<ll> vec;
    for (int i=1;i<=N;++i) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());

    cout << checkv(vec);
}
