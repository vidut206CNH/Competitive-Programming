#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;++i) {
		vector<int> b(n);
		for(int j=0;j<n;++j) cin >> b[j];
		sort(b.begin(),b.end());
		a[i] = b[n/2];
	}
	sort(a.begin(),a.end());
	cout << a[n/2];
}