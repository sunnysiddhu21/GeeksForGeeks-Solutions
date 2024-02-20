//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int> &vis,
            vector<int> adj[], int timeIn[], int low[], vector<vector<int>> &bridges) {
                vis[node] = 1;
                timeIn[node] = low[node] = timer;
                timer++;
 
                for(auto it: adj[node]) {
                    if (it == parent) continue; //skip the parent
                    if (vis[it] == 0) {
                        //if not visited
                        dfs(it, node, vis, adj, timeIn, low, bridges);
                        //when it is returning get the lowest possibe number 
                        low[node] = min(low[node], low[it]);
                        // node --- it is it a bridge lets check
                        if (low[it] > timeIn[node]) {
                            //if the lowest of the adj node is greater than 
                            //the current node means there is bridge that it 
                            //can't reach the current node by some other node
                            vector<int> bridge((node <= it) ? vector<int>{node, it} : vector<int>{it, node});
                            bridges.push_back(bridge);
                        }
                    }
                    else {
                        //if it is visited
                        //just take the lowest one if there and move
                        low[node] = min(low[node], low[it]);
                    }
                }
            }
public:
	vector<vector<int>>criticalConnections(int n, vector<int> adj[]){
	    // Code here
     //first create the adjacency list
        // vector<int> adj[n];
        // for(auto it: connections) {
        //     int u = it[0], v = it[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        //for dfs traversal
        vector<int> vis(n, 0);
        //tarjan algorithm we need time and low time data structure array simply
        int timeIn[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, timeIn, low, bridges);
        sort(bridges.begin(), bridges.end());
        return bridges;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends