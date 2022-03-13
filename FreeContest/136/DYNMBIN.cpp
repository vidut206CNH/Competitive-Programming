#include <bits/stdc++.h>
using namespace std;

struct TQuery 
{
    int t, u, v, x;
};

vector<TQuery> Q;
int n, q;
string s;

const int K = 3, N = 200002;
const int mod[K] = {1000696969, 987654319, 987654323};
const int BASE = 5;

int pw[K][N], inv_pw[K][N];
int prefixsum_pw[K][N];

int Pow (int a, int b, int mod) 
{
    if (b == 0) 
        return 1;
    long long c = Pow(a, b / 2, mod);
    c = c * c % mod;
    if (b % 2 == 1) 
        c = c * a % mod;
    return c;
}

struct TSegTree
{
    int f[K][4 * N];
    int lazy[4 * N];
    int lt[4 * N], rt[4 * N];

    void down(int id) 
    {
        if (lazy[id] == 1) 
        {
            for (int k=0; k<K; ++k) 
            {
                f[k][id * 2] = (prefixsum_pw[k][rt[id * 2]] - prefixsum_pw[k][lt[id * 2] - 1] + mod[k]) % mod[k];
                f[k][id * 2 + 1] = (prefixsum_pw[k][rt[id * 2 + 1]] - prefixsum_pw[k][lt[id * 2 + 1] - 1] + mod[k]) % mod[k];
            }
            lazy[id * 2] = lazy[id * 2 + 1] = 1;
        }
        else if (lazy[id] == 2) 
        {
            for (int k=0; k<K; ++k) 
            {
                f[k][id * 2] = (prefixsum_pw[k][rt[id * 2]] - prefixsum_pw[k][lt[id * 2] - 1] + mod[k]) % mod[k] * 2 % mod[k];
                f[k][id * 2 + 1] = (prefixsum_pw[k][rt[id * 2 + 1]] - prefixsum_pw[k][lt[id * 2 + 1] - 1] + mod[k]) % mod[k] * 2 % mod[k];
            }
            lazy[id * 2] = lazy[id * 2 + 1] = 2;
        }
        lazy[id] = 0;
    }

    void init(int id, int l, int r) 
    {
        if (l == r) 
        {
            for (int k=0; k<K; ++k) 
                f[k][id] = ((long long)(s[l] -'0' + 1) * pw[k][l]) % mod[k];
        }
        else 
        {
            int m = (l + r) / 2;
            init(id * 2, l, m);
            init(id * 2 + 1, m + 1, r);
            for (int k=0; k<K; ++k) 
                f[k][id] = (f[k][id * 2] + f[k][id * 2 + 1]) % mod[k];
        }
        lt[id] = l;
        rt[id] = r;
    }

    void update (int id, int l, int r, int u, int v, int w) 
    {
        if (r < u || v < l) 
            return;
        if (u <= l && r <= v) 
        {
            lazy[id] = w + 1;
            for (int k=0; k<K; ++k) 
                f[k][id] = ((prefixsum_pw[k][r] - prefixsum_pw[k][l - 1] + mod[k]) % mod[k] * (w + 1) % mod[k]);
        }
        else 
        {
            down(id);
            update(id * 2, l, rt[id * 2], u, v, w);
            update(id * 2 + 1, lt[id * 2 + 1], r, u, v, w);
            for (int k=0; k<K; ++k) 
            {
                f[k][id] = (f[k][id * 2] + f[k][id * 2 + 1]) % mod[k];

            }
        }

        assert (f[0][id] >= 0);
    }
    int get (int id, int l, int r, int u, int v, int k) 
    {
        if (r <u || v < l) 
            return 0;
        if (u <= l && r <= v) 
            return f[k][id];
        if (k == 0)
            down(id);
        return (get(id * 2, l, rt[id * 2], u, v, k) + get(id * 2 + 1, lt[id * 2 + 1], r, u, v, k)) % mod[k];
    }

    int compare (int u, int v, int len)
    {
        long long t1, t2;
        for (int k=0; k<K; ++k) 
        {
            t1 = get(1, 1, n, u, u + len - 1, k);
            t1 = t1 * inv_pw[k][u - 1] % mod[k];
            t2 = get(1, 1, n, v, v + len - 1, k);
            t2 = t2 * inv_pw[k][v - 1] % mod[k];
            if (t1!=t2) 
                return 0;
        }
        return 1;
    }
} it;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    cin >> q;
    Q.resize(q);
    for (auto &i : Q) 
    {
        cin >> i.t >> i.u >> i.v >> i.x;
    }

    for (int k=0; k<K; ++k) 
    {
        pw[k][0] = 1;
        prefixsum_pw[k][0] = 1;
        for (int i=1; i<=n; ++i) 
        {
            pw[k][i] = pw[k][i - 1] * (long long)BASE % mod[k];
            prefixsum_pw[k][i] = (prefixsum_pw[k][i - 1] + pw[k][i]) % mod[k];
        }
        inv_pw[k][n] = Pow(pw[k][n], mod[k] - 2, mod[k]);
        for (int i=n-1; i>=0; --i) 
            inv_pw[k][i] = inv_pw[k][i + 1] * (long long)BASE % mod[k];
    }

    int res;
    it.init(1, 1, n);
    for (auto &i : Q) 
    {
        if (i.t == 1) 
        {
            it.update(1, 1, n, i.u, i.v, i.x);
        }
        else 
        {
            res = it.compare(i.u, i.v, i.x);
            cout << res;
            flush(cout);
        }
    }
    return 0;
}
