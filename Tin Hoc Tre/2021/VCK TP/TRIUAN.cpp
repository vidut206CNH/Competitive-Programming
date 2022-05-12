#include <iostream>

using namespace std;

const int MAXN = 2000;
const int NMOD = 1000000007;

int n,m,k,l, w[10], h[10], tab[MAXN][MAXN], dx[10];
long long res, fRes = 0;

long long getwayscount ( int n , int m , int k ) {
    if ( k > n )
      return ( m % k == 0 ? 1 : 0 );

    else if ( k == 1 )
      return 1 ;

    else if ( k == n ) {
      long long f[MAXN];
      f [ 0 ] = 1 ;

      for ( int i = 1 ; i <= m ; i ++ )
        f [ i ] = (f [ i - 1 ] + ( i >= k ? f [ i - k ] : 0 )) % NMOD;

      return (f [ m ] % NMOD);
    }

    else if ( m % k > 0 )
      return 0 ;

    else {
      long long f[MAXN];

      int i = 0 ;
      while ( i < k )
        f [ i ++ ] = 1 ;

      while ( i <= m ) {
        f [ i ] = (f [ i - k ] + ( n - k + 1 ) * f [ i - 1 ]) % NMOD;
        int next_i = i + k ;
        for ( i ++ ; i < next_i && i < m ; i ++ )
          f [ i ] = (f [ i - 1 ] + f [ i - k ]) % NMOD;
      }

      return (f [ m ] % NMOD);
    }
  }
  
void find(int *x, int *y) {
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			if (tab[i][j]==0) {
				*x = i; 
				*y = j;
				return;
			}
}

bool check(int x, int y, int w, int h) {
	
    if ((x+w>m) || (y+h>n)) return false;
	
    for (int i=0; i<w; i++)
		for (int j=0; j<h; j++) 
			if (tab[i+x][j+y] == 1) return false;
	return true;
}

void fill(int x, int y, int w, int h, int value) {
	for (int i=0; i<w; i++)
		for (int j=0; j<h; j++) tab[i+x][j+y] = value;
}

int backTrace(int s) {
	if (s==k) {
		fRes = (fRes + res) % NMOD;
		return 0;
	}
	
	int i, j;
	find(&i, &j);
	for (int v=0; v<k; v++) {
		if ((dx[v]==0)&&(check(i,j,w[v],h[v]))) {
			fill(i,j,w[v],h[v],1);
			dx[v]=1;
			backTrace(s+1);
			fill(i,j,w[v],h[v],0);
			dx[v]=0;
		}
		
		if ((dx[v]==0)&&(w[v]!=h[v])&&(check(i,j,h[v],w[v]))) {
			fill(i,j,h[v],w[v],1);
			dx[v]=1;
			backTrace(s+1);
			fill(i,j,h[v],w[v],0);
			dx[v]=0;
		}
	}
}
  
int main() {
  freopen("23.in","r",stdin);
  freopen("23.a","w",stdout);
  
  cin>>n>>m>>k>>l;
  
  res = 1;
  for (int i=0; i<k; i++) {
    cin>>w[i]>>h[i];
	//cout<<getwayscount(n,m,l)<<endl;
	if (w[i]>h[i]) res = (res * getwayscount(h[i],w[i],l)) % NMOD;
	else res = (res * getwayscount(w[i],h[i],l)) % NMOD;
  }

  backTrace(0);
  
  cout<<fRes<<endl;
  
  //system("pause");
  return 0;
}  
