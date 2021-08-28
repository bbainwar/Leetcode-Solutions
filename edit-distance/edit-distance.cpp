class Solution {
public:
    int solution(string w1, string w2, int i, int j, vector<vector<int>>& dp){
        if(w2.size()==j){return w1.size()-i;}
        if(w1.size()==i){return w2.size()-j;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(w1[i]==w2[j]){return dp[i][j]=solution(w1, w2, i+1, j+1, dp);}
        else{
            int insert=solution(w1, w2, i, j+1, dp);
            int del=solution(w1, w2, i+1, j, dp);
            int replace=solution(w1, w2, i+1, j+1, dp);
            return dp[i][j]=1+min(insert, min(del, replace));
        }
    }
    int minDistance(string word1, string word2) {
        vector<int> temp(word2.size()+1, -1);
        vector<vector<int>> dp(word1.size()+1, temp);
        return solution(word1, word2, 0, 0, dp);
    }
};