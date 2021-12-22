#include<cstdio>
#include<stack>
using namespace std;

int n, a[33333], l[33333], r[33333];

void testcase() {
    scanf("%d", &n); for(int i = 0; i < n; ++i) scanf("%d", a+i);
    stack<int> st; l[0] = 0;
    for(int i = 1; i < n; ++i) if(a[i] > a[i-1]) l[i] = i, st.push(i-1);
    else {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        l[i] = st.empty() ? 0 : st.top() + 1;
    }
    st = stack<int>(); r[n-1] = n-1;
    for(int i = n-2; i >= 0; --i) if(a[i] > a[i+1]) r[i] = i, st.push(i+1);
    else {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        r[i] = st.empty() ? n-1 : st.top() - 1;
    }
    int res = 0;
    for(int i = 1; i < n; ++i) if((r[i] - l[i] + 1) * a[i] > (r[res] - l[res] + 1) * a[res]) res = i;
    printf("%d %d %d\n", (r[res] - l[res] + 1) * a[res], l[res] + 1, r[res] + 1);
}

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) testcase();
    return 0;
}
