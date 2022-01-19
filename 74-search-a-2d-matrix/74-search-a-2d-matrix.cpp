class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int row, int target){
        int n=matrix[0].size();
        int l=0, r=n-1, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int l=0, r=n-1, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                return searchRow(matrix, mid, target);
            }
            else if(matrix[mid][0]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
};