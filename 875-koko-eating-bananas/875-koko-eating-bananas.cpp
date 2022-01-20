class Solution {
public:
    bool check(vector<int>& piles, int h, long k){
        long hours=0;
        for(int i: piles){
            hours+=i/k;
            if(i%k!=0) hours++;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long low=1, high=1e12, mid;
        while(low<high){
            mid=low+(high-low)/2;
            if(check(piles, h, mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};