class Solution {
public:
  int brokenCalc(int s, int t) {
        int c=0;
        while(t!=s){
            if(t%2==0 && t>s){
                t/=2;
                c++;
            }
            else{
               t+=1; 
                c++;
            }
        }
        return c;
    }
};