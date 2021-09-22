class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> power(2*n);
        for(int i=0; i<n; i++){
            power[i]=gas[i]-cost[i];
            power[n+i]=power[i];
        }
        for(int i=0; i<n;  i++){
            if(power[i]<0){
                continue;
            }
            else{
                int presFuel=0;
                for(int j=i; j<i+n; j++){
                    presFuel+=power[j];
                    if(presFuel<0){
                        i=j;
                        break;
                    }
                    else if(j==i+n-1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};