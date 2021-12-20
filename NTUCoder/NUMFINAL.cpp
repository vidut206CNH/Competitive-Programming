#include <iostream>

using namespace std;

int numfinal(int a,int b){
    long long x=1,y=a%10;
    while(b>0){
        if(b%2 == 1){
            x = (x*y)%10;
        }
        y = (y*y)%10;
        b /= 2;
    }
    return x%10;
}

int main() {
	long long a, N;
	cin >> a >> N;
	cout << numfinal(a, N);
}
