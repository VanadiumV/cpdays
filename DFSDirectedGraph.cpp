//Detect Cycle in A Directed Graph
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m, cycle = 0; cin >> n >> m;
 
    vector<int> adj[n+1], vis(n+1), inStack(n+1);
 
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
 
    function<void(int)> dfs = [&](int n)
    {
        vis[n] = 1;
        inStack[n] = 1;
 
        for(auto &i : adj[n])
        {
            if(vis[i] == 1 && inStack[i] == 1) cycle = 1;
            else if(!vis[i]) dfs(i);
        }
 
        inStack[n] = 0;
    };
 
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) dfs(i);
    }
  
    cout << (cycle ? "Cycle" : "No Cycle");
}