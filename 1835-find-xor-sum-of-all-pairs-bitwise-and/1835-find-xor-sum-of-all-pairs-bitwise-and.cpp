class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ors1=0, ors2=0;
        for(int i:arr1) ors1^=i;
        for(int i:arr2) ors2^=i;
        return ors1&ors2;
    }
};