class Solution {
public:
    int dp[301];

    int helper(int i, string s, set<string>&wordDict){
        
        if(s.size()==i) return 1;
        string temp;
        if(dp[i]!=-1) return dp[i];
        for (int j= i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(helper(j+1,s,wordDict))return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }


    bool wordBreak(string s, vector<string>& wordDict) {

        set<string>st;
        memset(dp, -1, sizeof dp);
        for (auto a:wordDict) st.insert(a);
        return helper(0,s,st);
    }
};