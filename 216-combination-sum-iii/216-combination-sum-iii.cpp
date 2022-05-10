class Solution {
public:
    vector<vector<int>> ans;
    void sol(int k, int n, int s, vector<int> tillNow){
        if(k==0 && n==0){
            ans.push_back(tillNow);
            return;
        }
        if(s>9 || n<0 || k==0) return;
        for(int i=s; i<=9; i++){
            tillNow.push_back(i);
            sol(k-1, n-i, i+1, tillNow);
            tillNow.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        sol(k, n, 1, {});
        return ans;
    }
};