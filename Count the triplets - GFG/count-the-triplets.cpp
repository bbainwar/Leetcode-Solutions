// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    unordered_map<int, int> umap;
	    for(int i=0; i<n; i++){
	        umap[arr[i]]++;
	    }
	    int count=0;
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n; j++){
	            int t=arr[i]+arr[j];
	            if(umap[t]!=0){
	                count++;
	            }
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends