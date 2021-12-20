#include <iostream>

using namespace std;

int main() {
	int a,b,ans;
	cin >> a >> b;
	a = a%100;
	b = b%100;
	ans = (a*b)%100;
	if (ans%3==0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}