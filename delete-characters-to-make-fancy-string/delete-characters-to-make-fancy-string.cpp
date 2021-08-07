class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int ind=0, n=s.size();
        while(ind<n){
            char pres=s[ind];
            int count=0;
            while(true){
                if(s[ind]!=pres){
                    break;
                }
                count++; ind++;
            }
            if(count>2){count=2;}
            for(int i=1; i<=count; i++)
                ans.push_back(pres);
        }
        return ans;
    }
};