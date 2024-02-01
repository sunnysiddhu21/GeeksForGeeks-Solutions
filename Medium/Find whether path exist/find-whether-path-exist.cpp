//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   
    public:
    int n;
    int m;
    int arr[4]={-1,1,0,0};
    int brr[4]={0,0,-1,1};
    bool solve(int x,int y,vector<vector<int>>&grid)
    {
        if(x<0 ||x>=n || y<0 || y>=m)
        {
            return 0;
        }
        if(grid[x][y]==2)
        {
            return 1;
        }
        if(grid[x][y]==0)
        {
            return 0;
        }
        int ans=0;
       grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            ans=ans|solve(x+arr[i],y+brr[i],grid);
        }
        return ans;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return solve(i,j,grid);
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends