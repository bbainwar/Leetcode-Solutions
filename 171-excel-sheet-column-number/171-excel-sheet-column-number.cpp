class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int n=columnTitle.size(), ans=0;
        for(int i=0; i<n; i++){
            ans+=(columnTitle[i]-'A'+1)*pow(26, i);
        }
        return ans;
    }
};