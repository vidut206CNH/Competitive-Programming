#include <bits/stdc++.h>

using namespace std;


int main() {
	int n;cin >> n;
	int sum=0,x,w,cnt=0;
	int a[6] = {20,15,10,5,2,1};
	stack<int> st;
	while(n) {
		cin >> x;
		st.push(x);
		sum += x;
		--n;
	}
	cin >> w;
	while(sum>w) {
		sum -= st.top();
		cnt++;
		st.pop();
	}
	if(sum==w) {
		cout << cnt;
		return 0;
	}
	vector<int> sumz(max(21,w+1),0);
	sumz[1] = 1;
	sumz[2] = 1;
	sumz[5] = 1;
	sumz[10] = 1;
	sumz[15] = 1;
	sumz[20] = 1;	
	for(int i=3;i<=sumz.size()-1;++i) {
		if(sumz[i]==0) {
			sumz[i] = 1000;
			for(int j=i-1;j>=i/2;--j) {
				sumz[i] = min(sumz[i] , sumz[j]+sumz[i-j]);
			}
		}
	}
	if(sum<w) {
		int cnt1 = sumz[w-sum];
		if (cnt1>2) {
			sum = w-sum;
			int t = cnt1;
			int i=1;
			while(i<t && !st.empty()) {
				cnt1 = min(cnt1,i+sumz[sum+=st.top()]);
				st.pop();
				++i;
			}
		}
		cnt += cnt1;
	}
	cout << cnt;
}