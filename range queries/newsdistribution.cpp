//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

void dfs(int cur, vector<int> edges[], vector<int> &vis, vector<int> &comp) {
    vis[cur] = 1;
    comp.push_back(cur);
    for (auto x : edges[cur]) {
        if (!vis[x]) {
            dfs(x, edges, vis, comp);
        }
    }
}

// TC: O(V + E) -> O(N + sum(ki))
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> edges[n]; //adjacency list

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        vector<int> group(s);
        for (int j = 0; j < s; j++) {
            cin >> group[j];
            group[j]--; //converting to 0 based indexing
            if (j != 0) {
                edges[group[j]].push_back(group[j - 1]);
                edges[group[j - 1]].push_back(group[j]);
            }
        }
    }

    vector<int> vis(n, 0), ans(n);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, edges, vis, comp);
            for (auto x : comp) {
                ans[x] = comp.size();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // TC: O(N + sum(ki)) -> ki -> individual group sizes
    // SC: O(N) + sum(ki)
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
