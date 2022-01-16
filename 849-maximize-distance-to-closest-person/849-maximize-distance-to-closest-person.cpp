class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int gMax=0, lMax=0, n=seats.size();
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==0){
                while(i<seats.size() && seats[i]==0){
                    lMax++;
                    i++;
                }
                gMax=max(lMax, gMax);
                lMax=0;
            }
        }
        gMax=ceil((double)gMax/2);
        if(seats[0]==0){
            int count=0, ind=0;
            while(ind<seats.size()&& seats[ind]==0){
                count++;
                ind++;
            }
            gMax=max(count, gMax);
        }
        if(seats[n-1]==0){
            int count=0, ind=n-1;
            while(ind>=0 && seats[ind]==0){
                count++;
                ind--;
            }
            gMax=max(count, gMax);
        }
        return gMax;
    }
};