class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        char carry='0';
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0, j=0;
        int sa=a.size(), sb=b.size();
        if(sa>sb){
            for(int ind=0; ind<(sa-sb); ind++){
                b+='0';
            }
        }
        else{
            for(int ind=0; ind<(sb-sa); ind++){
                a+='0';
            }
        }
        cout<<a<<"\n"<<b<<"\n";
        int count=0;
        while(i<a.size() && j<b.size()){
            count++;
            if(carry=='0'){
                if((a[i]=='0'&&b[j]=='1')||(a[i]=='1'&&b[j]=='0')){
                    ans+='1';
                }
                else if(a[i]=='1'&&b[j]=='1'){
                    // cout<<"here1";
                    carry='1';
                    ans+='0';
                }
                else{
                    ans+='0';
                }
            }
            else{
                if((a[i]=='0'&&b[j]=='1')||(a[i]=='1'&&b[j]=='0')){
                    cout<<"here1";
                    ans+='0';
                }
                else if(a[i]=='1'&&b[j]=='1'){
                    ans+='1';
                }
                else{
                    ans+='1';
                    carry='0';
                }
            }
            i++; j++;
        }
        cout<<ans<<endl<<count;
        if(carry=='1'){
            cout<<"here";
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};