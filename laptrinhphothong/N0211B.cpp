#include <iostream>

using namespace std;

int main() {
	long long x1,y1,x2,y2,x3,y3;
	long long a1,a2;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a1 = (x2-x1)*(y3-y2);
	a2 = (x3-x2)*(y2-y1);
	if (((x1==x2) && (x2==x3)) || ((y1==y2) && (y2==y3))) {
		cout << "YES";
	}
	else {	
		if (a1==a2) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
}