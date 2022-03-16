class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> S;
        int n=popped.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(S.empty() || S.top()!=popped[j]) S.push(pushed[i]);
            while(!S.empty() && j<n && S.top()==popped[j])
            {
                j++;
                S.pop();
            }
        }
        return j==n;
    }
};