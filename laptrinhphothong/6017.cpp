#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	ll arr[n];
	ll sum = 0;
	for (int i=0;i<=n-1;++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i=0;i<=n-1;++i) {
		if (2*arr[i]==sum) {
			cout << arr[i];
			break;
		}
		else {
			if (i==n-1) {
				cout << "N";
			}
		}
	}
}