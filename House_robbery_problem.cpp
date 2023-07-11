//Question link - https://shorturl.at/gitNZ

#include <bits/stdc++.h> 

long long int solve(vector<long long int> &nums){
    //BC
    int n = nums.size();
    long long int prev1 = nums[0];
    long long int prev2 = max(prev1, nums[1]);
    for(int i=2; i<n; i++){
        long long int curr = max(prev1 + nums[i], prev2);
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }

    vector<long long int> first, second;

    for(int i=0; i<n; i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }

    long long int sol1 = solve(first);
    long long int sol2 = solve(second);
    return max(sol1, sol2);
}
