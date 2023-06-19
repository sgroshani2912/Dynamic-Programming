// Problem Statement - You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps. You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor.

//Recursive approach
class Solution {
public:

    int solve(vector<int>& cost, int n){
        //BC
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        int ans = min(solve(cost, n-1), solve(cost, n-2)) + cost[n];
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

//Top down approach
class Solution {
public:

    int solve(vector<int>& cost, int n, vector<int> &dp){
        //BC
        if(n==0){
            return dp[0] = cost[0];
        }
        if(n==1){
            return dp[1] = cost[1];
        }
        if(dp[n]) return dp[n];
        dp[n] = min(solve(cost, n-1, dp), solve(cost, n-2, dp)) + cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};


//Bottom up approach, TC = O(N), SC = O(N)
class Solution {
public:

    int solve(vector<int>& cost, int n, vector<int> &dp){
        //BC
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<=n; i++){
            dp[i] = min(dp[i-1] , dp[i-2]) + cost[i]; 
        }
        return dp[n];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};


//Space optimization, TC = O(N), SC = O(1)
class Solution {
public:

    int solve(vector<int>& cost, int n){
        //BC
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = cost[n];
        for(int i=2; i<=n; i++){
            curr = min(prev1 , prev2) + cost[i]; 
            prev1 = prev2;
            prev2 = curr;

        }
        return curr;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};
