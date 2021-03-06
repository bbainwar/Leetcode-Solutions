// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void sol(vector<vector<int>>& image, int col, int r, int c, int ncol){
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size()) return;
        if(image[r][c]!=col) return;
        
        image[r][c]=ncol;
        
        sol(image, col, r-1, c, ncol);
        sol(image, col, r+1, c, ncol);
        sol(image, col, r, c-1, ncol);
        sol(image, col, r, c+1, ncol);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(), m=image[0].size();
        int col=image[sr][sc];
        if(col==newColor) return image;
        sol(image, col, sr, sc, newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends