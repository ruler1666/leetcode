class Solution {
public:
    int solve(int n , vector<int>&dp,vector<int>&nums){
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int cost= nums[n]+solve(n-2,dp,nums);
        int skip=solve(n-1,dp,nums);
        return dp[n]=max(cost,skip);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};