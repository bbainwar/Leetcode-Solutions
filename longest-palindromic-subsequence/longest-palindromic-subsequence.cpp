class Solution {
public:
    //int dp[1001][1001];
    /*
    int solution(string s, int left, int right){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(left==right){
            return dp[left][right]=1;
        }
        
        if(s[left]==s[right]){
            return dp[left][right]=2+solution(s, left+1, right-1);
        }
        else{
            return dp[left][right]=max(solution(s, left+1, right), solution(s, left, right-1));
        }
        
    }
    */
    int longestPalindromeSubseq(string s) {
        //memset(dp, -1, sizeof(dp));
        int n=s.size();
        int dp[n][n];
        
        for(int i=0; i<n; i++)
            dp[i][i]=1;
        
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1])
                dp[i][i+1]=2;
            else
                dp[i][i+1]=1;
        }
        
        for(int j=2; j<n; j++){
            for(int i=j-2; i>=0; i--){
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
        //return solution(s, 0, s.size()-1);
    }
};