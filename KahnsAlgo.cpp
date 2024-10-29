vector<int> topologicalSort(vector<vector<int> >& adj, int V) {

    vector<int> indegree(V);

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
 
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
       
        for (auto it : adj[node]) {
            indegree[it]--;
           
            if (indegree[it] == 0)
                q.push(it);
        }
    }
 
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }
 
    return result;
}