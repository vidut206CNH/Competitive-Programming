#include <iostream>
#include<iomanip>
using namespace std;

int num(int a) {
	if (a==1)  return 1;
	else {
		return (a*a - (num(a-1)+a-2) - a +1);
	}
}

int main() {
	int i,j,k,a;
	cin >> i;
	for (k=1;k<=i;k++) {
		for (j=1;j<=k;j++) {
			a = num(k) + j-1;
			if (a<=9) cout << a << "   ";
			if ((a>9) && (a<=99)) cout << a << "  ";
		    if (a>99) cout << a << " ";
		}
		cout << "\n";
	}
}