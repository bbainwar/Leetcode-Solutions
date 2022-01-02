class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size(), ans=0;
        vector<int> rem(60, 0);
        for(int i: time){
            rem[i%60]++;
        }
        
        ans+=rem[0]*(rem[0]-1)/2;
        ans+=rem[30]*(rem[30]-1)/2;
        
        for(int i=1; i<30; i++){
            ans+=(rem[i]*rem[60-i]);
        }
        return ans;
    }
};