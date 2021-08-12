class Solution {
public:
    int heightChecker(vector<int>& height) {
        vector<int> expected(height.size());
        for(int i=0; i<height.size(); i++)
            expected[i]=height[i];
        sort(expected.begin(), expected.end());
        int count=0;
        for(int i=0; i< height.size(); i++){
            if(height[i]!=expected[i])
                count++;
        }
        return count;
    }
};