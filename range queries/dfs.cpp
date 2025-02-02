#include<iostream>
#include "stack.h"
#include <vector>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<int>adj[], int vis[], vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        //traverrse all its neighbours
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj,vis,ls);
            }
        }
    }
public:
//fxn to return a list containing the dfs traversal of the graph 
vector<int> dfsOfGraph(int v, vector<int> adj[]){
    int vis[V]= {0};
    int start =0;
    vector<int> ls;
    dfs(start,adj,vis,ls);
    return ls;
}
};
