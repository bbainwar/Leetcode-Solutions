class Solution {
public:
    vector<vector<int>> allCand; 
    void findCombination(vector<int> candidate, int target, int start, vector<int> tillNow){
        if(target<0 || start>=candidate.size())
            return;
        if(target==0){
            allCand.push_back(tillNow);
            return;
        }
        tillNow.push_back(candidate[start]);
        findCombination(candidate, target-candidate[start], start, tillNow);
        
        tillNow.pop_back();
        findCombination(candidate, target, start+1, tillNow);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findCombination(candidates, target, 0, {});
        //vector<vector<int>> ans(allCand.begin(), allCand.end());
        return allCand;
    }
};