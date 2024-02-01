//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int n;
    int m;
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid){
        n=grid.size();
        m=grid[0].size();
        vis[i][j]=1;
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 'X' && !vis[x][y]){
                dfs(x,y,vis,grid);
            }
        }
         
            
        
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='X'){
                    cnt++;
                    dfs(row,col,vis,grid);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends