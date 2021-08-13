class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                par.push(s[i]);
            else if(par.empty()){
                return false;
            }
            else if((par.top()=='(' && s[i]==')')||(par.top()=='{' && s[i]=='}')||(par.top()=='[' && s[i]==']')){
                par.pop();
            }
            else{
                return false;
            }
        }
        return par.empty()?true:false;
    }
};