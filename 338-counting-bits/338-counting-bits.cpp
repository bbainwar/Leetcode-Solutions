class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for(int i=0; i<=num; i++){
            int temp=i;
            while(temp){
                if(temp%2==1){
                    ans[i]++;
                }
                temp=temp>>1;
            }
        }
        return ans;
    }
};