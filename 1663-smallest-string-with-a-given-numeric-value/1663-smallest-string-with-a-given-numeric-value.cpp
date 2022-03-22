class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0; i<n; i++){
            ans+='a';
            k-=1;
        }
        int ind=n-1;
        while(k>0 && ind>=0){
            int add=min(25, k);
            k-=add;
            ans[ind]+=add;
            ind--;
        }
        return ans;
    }
};