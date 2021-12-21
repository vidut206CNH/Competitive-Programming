#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n, cnt1, cnt2;
	cin >> n;
	cnt1 = n / 4 + 1;
	cnt2 = n / 3 + (n % 3 != 0);
	cout << max(cnt2 - cnt1, 0LL);


}