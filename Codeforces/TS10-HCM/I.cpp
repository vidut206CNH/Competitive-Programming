#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, Max = 0, ans = 1;
	cin >> n;
	vector<int> ar(1001, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		for (int i = a + 1; i <= b; ++i) {
			ar[i]++;
			if (ar[i] > Max) {
				ans = 1;
				Max = ar[i];
			}
			else if (ar[i] == Max) ans++;
		}
	}
	cout << ans;

}