#include <iostream>

using namespace std;

int main() {
	double a,b;
	long long count = 0;
	cin >> a >> b;
	if ((a-(long long)a) <= 0) {
		count +=1;
	}
	if ((b-(long long)b) >= 0) {
		count +=1; 
	}
	count += (long long)b-a;
	cout << count;
}