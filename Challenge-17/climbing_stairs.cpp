class Solution {
public:
    int climbStairs(int n) {

        static int memo[46] = {0};

        if (n==1)return 1;
        if(n==2)return 2;
        if(memo[n]!=0)return memo[n];

        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
        
    }
};