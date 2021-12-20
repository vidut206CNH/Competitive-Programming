#include <iostream> 
#include <string>
using namespace std;

int main() {
	int n;
	int a;
	int cnt1=0,cnt2=0;
	cin >> n;
	string res = "NO";
	for (int i=0;i<n;++i) {
		cin >> a;
		if (a==100) {
			cnt1 += 1;
		}
		else {
			cnt2 += 1;
		}
	}
	if (cnt1 % 2 == 0) {
		if (cnt1==0) {
			if (cnt2 %2 == 0) {
			res = "YES";
			}
		}
		else {
			res = "YES";
		}
	}
	cout << res;
}