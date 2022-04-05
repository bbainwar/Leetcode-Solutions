class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int r=height.size()-1, l=0;
        int maxm=INT_MIN;
        while(l<r){
            // cout<<l<<" "<<r<<endl;
            maxm=max(min(height[l], height[r])*(r-l), maxm);
            
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxm;
      
        // int l, r, maxm=INT_MIN;
        // for(int i=0; i<height.size(); i++){
        //     for(int j=1; j<height.size(); j++){
        //         int vol=min(height[i], height[j])*(j-i);
        //         if(maxm<vol){
        //             maxm=vol;
        //             l=i;r=j;
        //         }
        //     }
        // }
        // cout<<l<<" "<<r;
        // return maxm;
    }
};