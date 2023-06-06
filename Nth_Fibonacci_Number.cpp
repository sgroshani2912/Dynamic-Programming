
#include<bits/stdc++.h>
using namespace std;


//Recursive solution, TC = 0(N)+0(N), SC = O(1)
int solve(int n){
        //BC
        if(n==0 || n==1){
                return n;
        }
        return solve(n-1) + solve(n-2);
}

//Top-down approach solution, TC = O(N), SC = O(1)
int solve2(int n, vector<int> &dp){
        //BC as it is
        if(n==0 || n==1){
                return n;
        }
        if(dp[n] != -1){
              return dp[n];
        }
        return dp[n] = solve2(n-1, dp) + solve2(n-2, dp);

}

//Bottom-up approach solution, TC=O(N), SC=O(N)
int solve3(int n, vector<int> &dp){
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}

//Space optimisation, TC = O(N), SC = O(1)
int solve4(int n){
        int prev1 = 0;
        if(n==0) return prev1;

        int prev2 = 1;
        if(n==1) return prev2;

        int curr;

        for(int i=2; i<=n; i++){
                curr = prev1 + prev2;
                prev1 = prev2;
                prev2 = curr;
        }
        return curr;
}

int main()
{
        int n; 
        cin>>n;

        // vector<int> dp(n+1, -1);

        // cout<<solve(n)<<endl;
        // cout<<solve2(n,dp)<<endl;
        // cout<<solve3(n, dp)<<endl;
        cout<<solve4(n)<<endl;

        return 0;

        
}
