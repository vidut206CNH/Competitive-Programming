#include<bits/stdc++.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, Max = 0, x, y;
	set<int> se;
	cin >> n;
	map<int, pair<int, int> > mp;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		se.insert(x);
		if (mp.count(x)) {
			mp[x].first = max(mp[x].first, y);
			mp[x].second = min(mp[x].second, y);
		}
		else {
			mp[x].first = y;
			mp[x].second = y;
		}
	}
	auto it1 = se.begin();
	auto it2 = it1;
	++it2;
	while (it2 != se.end()) {
		if (mp[*it1].first > mp[*it2].second) {
			cout << "yes";
			return 0;
		}
		++it1;
		++it2;
	}
	cout << "no";


}