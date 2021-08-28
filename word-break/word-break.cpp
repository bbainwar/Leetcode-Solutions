class Solution {
public:
    bool solution(string s, vector<string> dict, int sInd, vector<int>& dp){
        int stringSize=s.size(), dictSize=dict.size();
        if(sInd==stringSize){return true;}
        if(dp[sInd]==1){return true;}
        if(dp[sInd]==0){return false;}
        
        bool ans=false;
        for(int i=0; i<dictSize; i++){
            int presDictSize=dict[i].size();
            if(sInd+presDictSize<=stringSize && s.substr(sInd, presDictSize)==dict[i]){
                ans=ans||solution(s, dict, sInd+presDictSize, dp);
            }
        }    
        if(ans){dp[sInd]=1;}else{dp[sInd]=0;}
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solution(s, wordDict, 0, dp);
    }
};