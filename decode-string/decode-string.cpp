class Solution {
public:
    bool isSmallAlphabet(char c){
        if(c>='a' && c<='z')
            return true;
        return false;
    }
    bool isNumber(char c){
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    void dec(stack<char> &st){
        string temp="";
        while(isSmallAlphabet(st.top())){
            //cout<<st.top();
            temp+=st.top();
            st.pop();
        }
        st.pop();
        int mul=0, place=0;
        
        while(!st.empty() && isNumber(st.top())){
            //cout<<st.top();
            mul+=(st.top()-'0')*pow(10, place);
            place++;
            st.pop();
        }
        
        reverse(temp.begin(), temp.end());
        for(int i=1; i<=mul; i++){
            for(char c: temp)
                st.push(c);
        }
    }
    string decodeString(string s) {
        stack<char> st;
        for(int ind=0; ind<s.size(); ind++){
            if(s[ind]!=']'){
                st.push(s[ind]);
            }
            else{
                dec(st);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};