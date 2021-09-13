class Solution {
public:
    vector<string> ans;
    void solution(string tillNow, int l, int r){
        if(l==0 && r==0){
            ans.push_back(tillNow);
            return;
        }
        if(l!=0){
            solution(tillNow+'(', l-1, r);
        }
        if(l!=r){
            solution(tillNow+')', l, r-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solution("", n, n);
        return ans;
    }
};