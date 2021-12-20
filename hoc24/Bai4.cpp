#include <iostream>

using namespace  std;


long gcd(long a, long b) {
	long min=a,max=b;
	if (a>b) {
		min = b;
		max = a;
	}
	if (min==0) {
		return max;
	}
	else if (max%min==0) {
		return min;
	}
	else {
		return gcd(max-min,min);
	}
}

int main() {
	long n,p,count=0;
	cin >> n >> p;
	for (long x=1;x<=n;++x) {
		if (gcd(n,x)==p) {
			count +=1;
		}
	}
	cout << count;
}