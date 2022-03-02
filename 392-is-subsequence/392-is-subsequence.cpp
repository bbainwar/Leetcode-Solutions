class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)
            return true;
        int i=0, j=0;
        while(i<t.size()){
            if(t[i]==s[j]){
                if(j==s.size()-1)
                    return true;
                j++;
            }
            i++;
        }
        return false;
    }
};