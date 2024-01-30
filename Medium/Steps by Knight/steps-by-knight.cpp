//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N)
	{
	    int movesX[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int movesY[] = {-1, -2, -2, -1, 1, 2, 2, 1};
	    // Convert 1-based indexing to 0-based indexing
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;
    
        // Initialize the chessboard with -1 indicating unvisited cells
        vector<vector<int>> visited(N, vector<int>(N, -1));
    
        // Initialize the queue for BFS
        queue<pair<pair<int, int>, int>> q;
        q.push({{knightPos[0], knightPos[1]}, 0});
    
        // Mark the starting position as visited
        visited[knightPos[0]][knightPos[1]] = 0;
    
        while (!q.empty()) {
            pair<pair<int, int>, int> current = q.front();
            q.pop();
    
            if (current.first == make_pair(targetPos[0], targetPos[1])) {
                return current.second;
            }
    
            for (int i = 0; i < 8; ++i) {
                int nextX = current.first.first + movesX[i];
                int nextY = current.first.second + movesY[i];
    
                // Check if the next position is inside the board and not visited
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == -1) {
                    q.push({{nextX, nextY}, current.second + 1});
                    visited[nextX][nextY] = current.second + 1;
                }
            }
        }
    
        // If the target is not reachable
        return -1;
	    
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