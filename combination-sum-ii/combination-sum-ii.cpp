class Solution {
public:
    void findCombination(vector<int> candidates, int target, int index, vector<vector<int>>& allCombination, vector<int> tillNow){
        if(target==0){
            allCombination.push_back(tillNow);
            return;
        }
        
        if(target<0 || index>=candidates.size()) return;
        
        tillNow.push_back(candidates[index]);
        findCombination(candidates, target-candidates[index], index+1, allCombination, tillNow);
        
        tillNow.pop_back();
        while(index<candidates.size()-1 && candidates[index]==candidates[index+1]){
            index++;
        }
        findCombination(candidates, target, index+1, allCombination, tillNow);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> allCombination;
        findCombination(candidates, target, 0, allCombination, {});
        //vector<vector<int>> ans(allCombination.begin(), allCombination.end());
        return allCombination;
    }
};