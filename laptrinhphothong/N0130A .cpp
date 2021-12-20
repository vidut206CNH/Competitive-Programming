#include<iostream>

using namespace std;

int main() {
	long long a,b,m,ans;
	cin >> a >> b >> m;
	a = a%m;
	b = b%m;
	ans = (a*b)%m;
	cout << ans;
}