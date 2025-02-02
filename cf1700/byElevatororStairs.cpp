//IOT+ ai and ml projects for cisco
//byElevationStairs cf




//dp [i]      [j]  
// 1-N        0/1
//dp[i][0] ->min time to reach the ith floor and we r outside the lift 
//dp[i][1] ->                                         inside the lift

dp[1][0] = 1
dp[1][1] = c

for(int i=2;i<=n;i++){
    dp[i][0] = min(dp[i][0], dp[i-1][0] + a[i-1])
    dp[i][0] = min(dp[i][0], dp[i-1][0] + c + b[i-1])
//i didnt take the lift from the prev row i was already in the lift
dp[i][1] =  min(dp[i][1], dp[i-1][1] + c + b[i-1])
dp[i][1] =  min(dp[i][1], dp[i-1][1]  + b[i-1])
//ur inside the lift but u came out 
dp[i][0] =  min(dp[i][0], dp[i-1][1] + a[i-1])
}

cout<<min(dp[n][0],dp[n][1])<<endl;