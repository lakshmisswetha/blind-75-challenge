class Solution {
public:
    int rob(vector<int>& nums) {

        int pre1,pre2 = 0;
        for(int num : nums){
            int temp = pre1;
            pre1 = max ((num + pre2),pre1);
            pre2 = temp;

        }
        return pre1;
        
    }
};