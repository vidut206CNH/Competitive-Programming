#include<bits/stdc++.h>

using namespace std;

long long powz(long long n,long long k) {
	long long res = 1;
	while(k) {
		if(k%2==1) {
			res = ((res%100)*(n%100))%100;
		}
		n = (n*n)%100;
		k /= 2;
	}
	return res%100;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,k,res=1,t;
	cin >> n >> k;
	n %= 100;
	set <long long> se;
	vector<long long> ve;
	while(true) {
		t = se.size();
		se.insert(powz(n,k));
		if(se.size()==t) break;
		n = powz(n,k);
		ve.push_back(n);
		
	}
	for(auto x:ve) cout << x << ' ';
}