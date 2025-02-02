//TETRAHEDRON -> WITH DP

//TL-> 2secs

// STATE
// dp[i][j]=no of paths in which the ant ends up on j after exactly i steps

//TRANSITION
//dp[i][j]= dp[i-1][k] where k!=j
// DO SPACE OPTIMIZATION BEC OUR CONSTRAINT IS 10^7 IT WILL GIVE MLE 
//if we give a n*n soln

//dp->curr step     old-dp->prev step

//FINAL SUBPROBLEM -> dp[3]
//NEW transition-> dp[j] = old_dp[k] where j!=k

//BASE CASE
// old_dp[3]=1

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
#define ll long long
#define vll vector<long long>  
#define mod 998244353
const int n=1000005;
   


void solve(){
    int n;
    cin>>n;
    // vector<vector<int>>dp(n+1, vector<int>(4,0));
    // dp[0][3] = 1;

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<4;j++){
    //         for(int k=0;k<4;k++){
    //             if(j!=k){
    //                 dp[i][j]=(dp[i][j] + dp[i-1][k])%mod;
    //             }
    //         }
    //     }
    // }
    // cout<<dp[n][3]<<'\n';


//OPTIMIZATIONS
    vector<int>dp(4,0);
    vector<int>old_dp(4,0);

    old_dp[3] = 1;
int sum =1;
    for(int i=1;i<=n;i++){
        int cursum=0;
        for(int j=0;j<4;j++){
           dp[j]=(sum - old_dp[j] + mod)%mod;
           cursum =(cursum + dp[j])%mod;
                
            }
            sum =cursum;
            old_dp = dp;
       
    }
    cout<<dp[3]<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;cin>>t;
while(t--){
    solve();
}
return 0;
}