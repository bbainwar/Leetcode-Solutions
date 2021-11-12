class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        
        vector<vector<int>> merged;
        int left=0, right=0, compTo;
        while(right<n){
            compTo=intervals[left][1];
            while(right+1<n && intervals[right+1][0]<=compTo){
                right=right+1;
                compTo=max(compTo, intervals[right][1]);
            }
            merged.push_back({intervals[left][0], compTo});
            right=right+1;
            left=right;
        }
        return merged;
    }
};