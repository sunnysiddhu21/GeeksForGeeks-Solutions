//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    
	    int rowJumps[] = {-2,-2,-1,-1,1,1,2,2};
	    int colJumps[] = {1,-1,2,-2,2,-2,1,-1};
	    
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	    int ans = 1e9;
	    queue<pair<int,pair<int,int>>> q;
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    while(!q.empty()) {
	        int c = q.front().first;
	        int i = q.front().second.first;
	        int j = q.front().second.second;
	        q.pop();
	        
	        if(i==TargetPos[0] && j==TargetPos[1]) ans = min(ans,c);
	        else {
	            for(int k=0;k<8;k++) {
    	            int nr = i + rowJumps[k];
    	            int nc = j + colJumps[k];
    	            
    	            if(nr>=1 && nr<=N && nc>=1 && nc<=N && !vis[nr][nc]) {
    	                q.push({c+1,{nr,nc}});
    	                vis[nr][nc]=1;
    	            }
    	        }
	        }
	    }
	    return (ans==1e9)?-1:ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends