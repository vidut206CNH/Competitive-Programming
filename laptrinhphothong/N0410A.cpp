#include <iostream>

using namespace std;

int main() {
	int n,cnt=0;
	cin >> n;
	for (int i=1;i<=n;++i) {
		long long a;
		cin >> a;
		if (a%2==0) {
			++cnt;
		}
	}
	cout << cnt;
}