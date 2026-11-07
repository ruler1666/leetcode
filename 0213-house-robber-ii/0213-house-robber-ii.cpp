class Solution {
public:
    int solve(int i,int end, vector<int>&dp ,vector<int>&nums){
        if (i>end)return 0;
        if(dp[i]!=-1)return dp[i];
        int cost = nums[i]+ solve(i+2,end,dp,nums);
        int skip = solve(i+1,end,dp,nums);
        return dp[i]=max(cost,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
         vector<int> dp1(n, -1);
        int first = solve(0, n-2, dp1,nums);

        vector<int> dp2(n, -1);
        int second = solve(1, n-1, dp2,nums);
        return max(first, second);
    }
};