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
        for(int i=0; i<matrix.size(); i++){
            if(searchRow(matrix, i, target)){
                return true;
            }
        }
        return false;
    }
};