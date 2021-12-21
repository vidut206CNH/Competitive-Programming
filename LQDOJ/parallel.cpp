#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll a[12];
	while (true) {
		for (int i = 0; i < 12; ++i) {
			cin >> a[i];
			if (a[i] == 0) return 0;
		}
		sort(a, a + 12);
		if (a[0] != a[3] || a[4] != a[7] || a[8] != a[11]) {
			cout << "no";
		}
		else cout << "yes";
		cout << '\n';
	}
}