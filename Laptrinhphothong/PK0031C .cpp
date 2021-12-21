#include <iostream>

using namespace std;

int main() {
	int N,count=0;
	int count1=0,count2=0,count3=0;
	cin >> N;
	for (int i=0;i<=N-1;++i) {
		int a;
		cin >> a;
		if (a==1) {
			count1 +=1;
		}
		if  (a==2) {
			count2 +=1;
		}
		if (a==3) {
			count3 +=1;
		}
		if (a==4) {
			count +=1;
		}
	}
	count += count3;
	if (count2%2==0) {
		count += count2/2;
	}
	if (count2%2!=0) {
		count += count2/2 + 1;
	}
	if (count1-count3>0) {
		int a = count1-count3;
		count += a/4;
		count1 = a%4;
		if (count1 !=0) {	
			if (count2 % 2 != 0) {
				if (count1>2) {
					count += 1;
				}
			}
			else {
				count += 1;
			}
		}
	}
	cout << count;
}