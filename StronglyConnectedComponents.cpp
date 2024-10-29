#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, col = 0; cin >> n >> m;
 
    vector<int>adj[n + 1], radj[n + 1], vis(n + 1), ord;
 
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
 
    function<void(int)>dfs = [&](int node) {
        vis[node] = 1;
        for(auto &v : adj[node]) if(!vis[v]) dfs(v); 
        ord.push_back(node);
    };
 
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
 
    reverse(ord.begin(), ord.end());
    vis.assign(n + 1, 0);
 
    function<void(int)>dfs2 = [&](int node) {
        vis[node] = col;
        for(auto &i : radj[node]) if(!vis[i]) dfs2(i);
    };
 
    for(auto &i : ord) 
    {
        if(!vis[i])
        {
            col++; dfs2(i);
        }
    }
 
    cout << col << "\n";
 
    for(int i = 1; i <= n; i++) cout << vis[i] << " ";
}