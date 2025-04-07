class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp (target+1,-1);
        dp[0]=1;
        return helper(nums,target,dp);
        
    }

    int helper (vector<int>&nums, int target, vector<int>& dp){
        if(dp[target]!=-1) return dp[target];

        int res = 0;
        for (int num : nums){
            if (target>=num){
                res += helper(nums,target-num, dp);
            }
        }

        dp[target] = res;
        return res;

    }
};