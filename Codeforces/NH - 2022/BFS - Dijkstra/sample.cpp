#include <bits/stdc++.h>
#define N 82
using namespace std;
const int INF = 1000000000;
int m, n, stx, sty, enx, eny, stx1, sty1, dd[N][N], res = -1;
char c;
int turnx[4] = {1,0,0,-1}, turny[4] = {0,1,-1,0};
int u, v, x, y, lu, lv, lx, ly;
struct state{
    int u, v, x, y,step;
};
struct cmp{
    bool operator() (state a, state b) {
        return a.step > b.step;
    }
};
void BFS(){
    int check[N][N], step[N][N][N][N], kt[N][N][4];
    queue<state> q;
    q.push({stx1,sty1,stx,sty,0});
    
    while( !q.empty() ){
        state t = q.front();
        q.pop();
        int u = t.u, v = t.v, x = t.x, y = t.y;
        if( check[x][y] == dd[x+turnx[0]][y+turny[0]] + dd[x+turnx[1]][y+turny[1]] + dd[x+turnx[2]][y+turny[2]] + dd[x+turnx[3]][y+turny[3]]){
            continue;
        }
        for(int i = 0; i < 4; i++){
            lu = u + turnx[i], lv = v + turny[i];
            if( lu < 1 || lu > m || lv < 1 || lv > n){
                continue;
            }
            if( dd[lu][lv] ){
                if( lu == x && lv == y ){
                    lx = x+turnx[i], ly = y+turny[i];
                    if( lx < 1 || lx > m || ly < 1 || ly > n ){
                        continue;
                    }
                    if( dd[lx][ly] && !kt[x][y][i] ){
                        check[x][y]++;
                        kt[x][y][i] = 1;
                        step[x][y][lx][ly] = step[u][v][x][y] + 1;
                        q.push({x,y,lx,ly,step[x][y][lx][ly]});
                        if( lx == enx && ly == eny){
                            res = step[x][y][lx][ly];
                            return;
                        }
                    }
                }else{
                    if( !step[lu][lv][x][y] ){
                        step[lu][lv][x][y] = step[u][v][x][y] + 1;
                        q.push({lu,lv,x,y,step[lu][lv][x][y]});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> c;
            if( c != '#' ){
                dd[i][j] = 1;
            }
            if( c == '*'){
                stx1 = i, sty1 = j;
            }
            if( c == '$'){
                stx = i, sty = j;
            }
            if( c == '@'){
                enx = i, eny = j;
            }
        }
    }
    BFS();
    cout << res;
    return 0;
}