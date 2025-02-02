#include<iostream>
using namespace std;

struct Dsu{
    int n;
    vector<int>leader,sizes;

    Dsu(int _n){
        n = _n;
        leader.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<=n;i++){
            leader[i] = i;
            sizes[i] = 1;
        }
    }
    int getLeader(int node){
        if(node == leader[node]) return node;
        return leader[node] = getLeader(leader[node]);

    }

    void connect(int x,int y){
        int leader_x = getLeader(x);
        int leader_y = getLeader(y);
        if(leader_x == leader_y)return;

        if(sizes[leader_x] < sizes[leader_y]){
            swap(leader_x,leader_y);
            swap(x,y);
        }
        leader[leader_y] = leader_x;
        sizes[leader_x] += sizes[leader_y];
    }
}

//ISLANDS

Dsu dsu(n * m);

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j] == '0') continue;

        int node = i*m + j;

        for(int k=0;k<4;k++){
            int x = i + dx[k],y= j +dy[k];
            if(x<0 || y<0|| x>=n || y >=m)continue;
            if(grid[x][y] == '0')continue;

            int nbr = x*m + y;
            dsu.connect(node,nbr);
        }
    }
}

int ans=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int node = i*m + j ;
        if(node == dsu.getLeader(node))ans++;
    }
}
retu