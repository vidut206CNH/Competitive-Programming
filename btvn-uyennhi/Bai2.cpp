/*
 Author: Le Nguyen Uyen Nhi
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	auto it = lower_bound(a.begin(), a.end(), k);
	cout << (it - a.begin() + 1);
}