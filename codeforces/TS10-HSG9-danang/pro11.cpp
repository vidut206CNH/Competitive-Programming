#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	ll n, Min = 1e8 + 1, res = 0;
	cin >> n;
	n *= n;
	vector< vector<ll> > a;
	unordered_map<int, int> s;
	for (int i = 1; i * i <= n; ++i) {

		// store square value in hashmap
		s[i * i] = 1;
		if (s.find(n - i * i) != s.end()) {
			if (abs(sqrt(n - i * i) - i) < Min) {
				Min = abs(sqrt(n - i * i) - i);
				res = 1LL * sqrt(n - i * i) * i;
			}
		}
	}
	cout << res;
}