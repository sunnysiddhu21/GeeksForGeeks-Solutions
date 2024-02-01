//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int n;
    int m;
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,int &curr){
        grid[i][j]=2;
        curr++;
        
        for(int k=0; k<8; k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                dfs(nr,nc,grid,curr);
            }
        }
        return;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int curr=0;
                    dfs(i,j,grid,curr);
                    ans=max(ans,curr);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends