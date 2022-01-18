class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int num) {
        int i=0, n=flowerbed.size(), ans=0;
        if(n==1){
            if(flowerbed[i]==0){
                return num<=1;
            }
            else{
                return num==0;
            }
        }
        while(i<n){
            if(i==0){
                if(flowerbed[i+1]==0 && flowerbed[i]==0){
                    ans++;
                    i++;
                }
            }
            else if(i==n-1){
                if(flowerbed[i-1]==0 && flowerbed[i]==0){
                    ans++;
                    i++;
                }
            }
            else if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                ans++;
                i++;
            }
            i++;
        }
        cout<<ans;
        return ans>=num;
    }
};

// 001