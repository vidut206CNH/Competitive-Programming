#include <iostream>
#include <sstream>
using namespace std;

int main() {
	long long n,x;
	cin >> n;
	long long sum=0;
	string strn;
	stringstream ss;
	ss << n;
	ss >> strn;
	for (long long i=0;i<strn.size();++i) {
		stringstream si;
		si << strn[i];
		si >> x;
		sum += x;
	}
	if (n%sum == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}