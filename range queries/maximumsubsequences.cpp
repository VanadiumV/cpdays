 

 
 //CHANGES  in atcoder smooth subsequence
 void set(int i, int v)
    {
        Real_set(i, v, 0, 0, size);
    }

    long long Real_query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx) // no intersection
            return k;
        if (lx >= l && rx <= r)
            return seg[x];
        int m = (lx + rx) / 2;
        long long s1 = Real_query(l, r, 2 * x + 1, lx, m);
        long long s2 = Real_query(l, r, 2 * x + 2, m, rx);
        return operation(s1, s2);
    }

    long long query(int l, int r) // for actual range (l,r) , do (l,r+1) while querying
    {
        return Real_query(l, r, 0, 0, size);
    }
};

void solve()
{
    // segment tree bitch
    int n, k;
    cin >> n >> k;
    segtree dp;
    dp.init(6e5);
    vi a(n);
    input(a);
    for (int i = n - 1; i >= 0; i--)
    {
        int x = a[i];
        int l = max(x - k, 1LL), r = x;
        int mx = dp.query(l, r + 1); // so this is one part
        l = x, r = min(500000LL, x + k);
        mx = max(mx, dp.query(l, r + 1));
        dp.set(x, mx + 1);
    }
    cout << dp.query(1, 500001) << endl;
}
