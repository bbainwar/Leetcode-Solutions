bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int maxm=0, right=INT_MIN, n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=0; i<n; i++){
            if(intervals[i][0]>=right){
                maxm++;
                right=intervals[i][1];
            }
        }
        return n-maxm;
    }
};