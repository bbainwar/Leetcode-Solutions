class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> arr;
        for(auto a: trips){
            arr.push_back({a[1], a[0]});
            arr.push_back({a[2], -a[0]});
        }
        sort(arr.begin(), arr.end());
        int curr=0;
        for(int i=0; i<arr.size(); i++){
            curr+=arr[i].second;
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};