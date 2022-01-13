bool comp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int countArrow=0, left=0;
        for(int i=0; i<points.size(); i++){
            if(countArrow==0 || points[i][0]>left){
                countArrow++;
                left=points[i][1];
            }
        }
        return countArrow;
    }
};