class Solution {
public:
    int dp[105];
        
    int decode(string s, int b){
        if(b>s.size() || s[b]=='0'){
            return 0;
        }
        if(dp[b]!=-1) return dp[b];
        if(b==s.size()){
            return 1;
        }
        
        int ans=0;
        ans+=decode(s, b+1);
        string temp=s.substr(b, 2);
        if(temp>="10" && temp<="26"){
            // cout<<temp;
            ans+=decode(s, b+2);
        }
        
        dp[b]=ans;
        return ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return decode(s, 0);
    }
};