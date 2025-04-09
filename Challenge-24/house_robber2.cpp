class Solution {
public:

    int helper(vector<int> &nums,int start, int end){
        int prev1 =0, prev2 = 0;
        for (int i=start; i<=end; i++){
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max (nums[0],nums[1]);

        return max(helper(nums,0,n-2), helper(nums,1,n-1));
        
        
    }
};