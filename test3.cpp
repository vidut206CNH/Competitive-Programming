#include<bits/stdc++.h>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;

	while(getline(cin, s)) {
		cout << "\"" << s << "\"," << "\n";
	}
	
	#ifndef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif



}
