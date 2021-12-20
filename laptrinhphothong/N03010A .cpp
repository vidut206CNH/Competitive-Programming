#include<iostream>

using namespace std;

int main() {
	int a,b,count=0;
	cin >> a >> b;
	for (int i=a;i<=b;++i) {
		if (i%3==0) {
			count +=1;
		}
	}
	cout << count;
}