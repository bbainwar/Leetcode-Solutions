class Solution {
public:
    int scoreOfParentheses(string s) {
        int depths=0, ans=0, n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                depths++;
            }
            else{
                depths--;
                if(s[i-1]=='(' && s[i]==')') ans+=pow(2, depths);
            }
        }
        return ans;
    }
};