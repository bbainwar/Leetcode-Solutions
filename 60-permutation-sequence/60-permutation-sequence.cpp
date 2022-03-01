class Solution {
public:
    int fac(int n){
        int ans=1;
        for(int i=1; i<=n; i++) ans*=i;
        return ans;
    }
    string getPermutation(int n, int k) {
        if(k==fac(n)){
            string ans="";
            for(int i=n; i>0; i--){
                ans+=(i+'0');
            }
            return ans;
        }
        queue<int> seq;
        for(int i=n; i>0; i--){
            // cout<<k<<" ";
            if(k==0){
                seq.push(1);
            }
            else{
                int tf=fac(i-1);
                seq.push(ceil(((double)k)/tf));
                int rem=k%tf;
                if(rem==0)
                    k=tf;
                else
                    k=k%tf;
            }
        }
        // cout<<endl;
        // queue<int> temp=seq;
        // while(!temp.empty()){
        //     cout<<temp.front()<<" ";
        //     temp.pop();
        // }
        // cout<<endl;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string ans="";
        for(int i=1; i<=n; i++){
            int count=seq.front();
            seq.pop();
            for(int j=0; j<n; j++){
                if(nums[j]>0){
                    count--;
                    if(count==0){
                        ans+=('0'+nums[j]);
                        nums[j]=-1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};