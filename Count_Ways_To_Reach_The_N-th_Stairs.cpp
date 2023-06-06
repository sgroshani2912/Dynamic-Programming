#include <bits/stdc++.h> 

//Recursive approach, TC = O(N) + O(N), SC = O(N)
int solve(int nStairs, int curr_stair){
    if(curr_stair == nStairs){
        return 1;
    }
    if(curr_stair > nStairs){
        return 0;
    }

    return (solve(nStairs, curr_stair+1) + solve(nStairs, curr_stair+2)) % 1000000007;
}

//Top-down approach, TC = O(N), SC = O(N)
int solve2(int nStairs, int curr_stair, vector<int> &dp){
    if(curr_stair == nStairs){
        return dp[curr_stair] = 1;
    }
    if(curr_stair > nStairs){
        return dp[curr_stair] = 0;
    }
    if(dp[nStairs]) return dp[nStairs];
    return dp[curr_stair] = (solve(nStairs, curr_stair+1) + solve(nStairs, curr_stair+2)) % 1000000007;
}

// Bottom-up approach, TC = 0(N), SC = 0(N)
int solve3(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    return dp[n]%1000000007;
}

//Space optimisation, TC = 0(N), SC = 0(1)
int solve4(int n){
    int prev1 = 1;
    int prev2 = 1;

    for(int i=2; i<=n; i++){
        int curr = (prev1 + prev2)%1000000007;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int countDistinctWays(int nStairs) {
    // int curr_stair = 0;

    // vector<int> dp(nStairs+1, 0);
    // int ans = solve(nStairs, curr_stair);
    // int and = solve2(nStairs, curr_Stair, dp);

    int ans = solve3(nStairs);
    return ans;
    
}
