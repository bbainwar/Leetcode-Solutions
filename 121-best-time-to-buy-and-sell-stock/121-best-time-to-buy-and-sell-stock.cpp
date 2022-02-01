class Solution {
public:
    int minimum(int a, int b){
        if(a>b)
            return b;
        return a;
    }
    int maximum(int a, int b){
        if(a<b)
            return b;
        return a;
    }
    int maxProfit(vector<int>& prices) {
        /*int profit=0;
        int min = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(min>prices[i])
                min=prices[i];
            int temp = prices[i]-min;
            if(temp>profit)
                profit=temp;
        }
        return profit;
        */
        int min=prices[0];
        vector<int> minm(prices.size());
        minm[0]=min;
        for(int i=1; i<prices.size(); i++){
            min=minimum(min, prices[i]);
            minm[i]=min;
        }
        int max=INT_MIN;
        for(int i=0; i<prices.size(); i++){
            max=maximum(max, prices[i]-minm[i]);
        }
        return max;
    }
};