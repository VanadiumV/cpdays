ll f(int index, int sum, int tight, int n, string& x, vector<vector<vector<ll>>>& dp){
    if(index == n){
        if(sum == 0)
            return 1;
        return 0;
    }   
    
    if(dp[index][sum][tight] != -1)
        return dp[index][sum][tight];
    
    int max_limit = tight ? x[index] - '0' : 9;
    ll ans = 0;
    for(int curr_digit = 0; curr_digit <= max_limit; curr_digit++){
        int new_index = index + 1;
        int new_sum = sum - curr_digit;
        int new_tight = 0;
        if(tight && curr_digit == max_limit){
            new_tight = 1;
        }
        if(new_sum >= 0)
            ans = ans + f(new_index, new_sum, new_tight, n, x, dp);
    }
    return dp[index][sum][tight] = ans;
    
}
ll dp_way(ll x, int k){
    string a = to_string(x);
    
    int n = a.size();
    vector<vector<vector<ll>>> dp(n, 
        vector<vector<ll>>(k + 1, vector<ll>(2, -1)));
    
    
    // O(log10(x) * k * 2) * O(10)
    // dp[i][s][tight] = number of ways to fill the digits from i to n - 1
    // such that the sum = s and tight tells us if there is a restriction on
    // the ith digit
    
    return f(0, k, 1, n, a, dp);
}