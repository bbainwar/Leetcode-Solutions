class Solution {
public:
    vector<vector<string>> ans;
    int dp[16][16];
    bool checkPalin(string str, int start, int end){
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        while(start<end){
            if(str[start]!=str[end]){
                return dp[start][end]=0;
            }
            start++; end--;
        }
        return dp[start][end]=1;
    }
    void print(vector<string> arr){
        for(auto s: arr)
            cout<<s<<" ";
        cout<<"\n";
    }
    
    void generate(string str, int start, vector<string> tillNow){
        if(start>=str.size()){
            // print(tillNow);
            ans.push_back(tillNow);
        }
        int sz=start;
        while(true){
            if(sz<str.size()){
                if(checkPalin(str, start, sz)){
                    tillNow.push_back(str.substr(start, sz-start+1));
                    generate(str, sz+1, tillNow);
                    tillNow.pop_back();
                }
                sz++;
            }
            else{
                break;
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        memset(dp, -1, sizeof(dp));
        generate(s, 0, {});
        return ans;
    }
};