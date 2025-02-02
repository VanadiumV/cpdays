#include<iostream>
using namespace std;

const int N=20,M=4;
int dp[N][M][2];

int f(int index, string &s, int nonZeroCount,int tight){
    if(nonZeroCount > 3) return 0;
    if(index == s.size()) return 1;

    if(dp[index][nonZeroCount][tight] != -1) return dp[index][nonZeroCount][tight];

    int ans = 0;
    for(char c='0'; c<= (tight ? s[index] : '9');c++){
        ans = (ans + f(index+1,s,nonZeroCount + (c!='0'), tight && (c== s[index])));

    }
    return dp[index][nonZeroCount][tight] = ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    wile(t--){
        long long left,right;cin>>left>>right;left--;
        string l = to_string(left), r= to_string(right);

        memset(dp,-1,sizeof(dp));
        int leftAnswer = f(0,1,0,1);
        memset(dp,-1,sizeof(dp));
        int rightAnswer = f(0,r,0,1);

        cout<<rightAnswer = leftAnswer<<'\n';
    }
}