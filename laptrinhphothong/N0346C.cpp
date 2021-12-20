#include <iostream>

using namespace std;

long long sumsq( long long n) {
	long long ans=0;
	for (long long i=1;i<=n;++i) {
		ans += 4*i*i;
	}
	return ans;
}


int main() {
	int t;
	cin >> t;
	long long arr[t];
	for (int i=0;i<=t-1;++i) {
		long long a;
		cin >> a;
		arr[i] = sumsq(a);
	}
	for (int i=0;i<=t-1;++i) {
		cout << arr[i] << "\n";
	}
}