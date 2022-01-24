class Solution {
public:
    void print(vector<int>& total){
        for(int i: total) cout<<i<<" ";
        cout<<endl;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> power(2*n);
        for(int i=0; i<n; i++){
            power[i]=gas[i]-cost[i];
            power[n+i]=power[i];
        }
        // print(total);
        for(int i=0; i<n; i++){
            int presFuel=0, j;
            for(j=i; j<i+n+1; j++){
                presFuel+=power[j];
                if(presFuel<0) {
                    i=j;
                    break;
                }
                else if(j==i+n) return i;
            }
            
        }
        return -1;
    }
};