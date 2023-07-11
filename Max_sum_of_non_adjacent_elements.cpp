//Recursive approach
#include <bits/stdc++.h> 

int solve(vector<int> &nums, int i, int sum){
    //BC
    if(i>=nums.size()){
        return sum;
    }

    //Include
    int inc = solve(nums, i+2, sum + nums[i]);

    //Exclude
    int exc = solve(nums, i+1, sum);

    return max(inc, exc);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int ans = solve(nums, 0, 0);
    return ans;
}

//Top-down approach (Recursion + memoisation), TC = O(N), SC = O(N) + O(N)
#include <bits/stdc++.h> 

int solve(vector<int> &nums, int n, vector<int> &dp){
    //BC
    if(n<0){
        return 0;
    }
    if(n==0){
        return dp[0] = nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    //Include
    int inc = solve(nums, n-2, dp) +nums[n];

    //Exclude
    int exc = solve(nums, n-1, dp);

    return dp[n] = max(inc, exc);
}

int maximumNonAdjacentSum(vector<int> &nums){

    vector<int> dp(nums.size()+1, -1);
    int ans = solve(nums, nums.size()-1, dp);
    return ans;
}

//Bottom up approaach (iterative approach or tabulation method), TC = O(N), SC = O(N)
#include <bits/stdc++.h> 

int solve(vector<int> &nums, int n, vector<int> &dp){
    //BC
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){

    vector<int> dp(nums.size()+1, -1);
    int ans = solve(nums, nums.size()-1, dp);
    return ans;
}

//Space optimised approach, TC=O(N), SC=O(1)
#include <bits/stdc++.h> 

int solve(vector<int> &nums, int n){
    //BC
    int prev1 = nums[0];
    int prev2 = max(prev1, nums[1]);
    for(int i=2; i<=n; i++){
        int curr = max(prev1 + nums[i], prev2);
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int maximumNonAdjacentSum(vector<int> &nums){

    int ans = solve(nums, nums.size()-1);
    return ans;
}
