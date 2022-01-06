class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2){
        return v1[1]<v2[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comp);
        for(int i=0; i<trips.size(); i++){
            swap(trips[i][0], trips[i][2]);
        }
        
        int presReq=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > endTime;
        for(int i=0; i<trips.size(); i++){
            while(endTime.empty()==false && endTime.top()[0]<=trips[i][1]){
                presReq-=endTime.top()[2];
                endTime.pop();
            }
            endTime.push(trips[i]);
            presReq+=trips[i][2];
            if(presReq>capacity){
                return false;
            }
        }
        return true;
    }
};