#include <iostream>
using namespace std;

int jump(int  k, int n) {
    if(k%n == 0) return n;
    else return jump(k%n+n,k%n);
}

int main() {
	int N,K;
	cin >> N >> K;
	cout << jump(K,N);

}
