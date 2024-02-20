//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
    
    void dfs3(int node, vector<int> &vis, vector<vector<int>>& adjT,vector<int>&ans) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT,ans);
            }
        }
    }
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto &it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        
        vector<int>ans;
        vector<vector<int>>res;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                dfs3(i,vis,adjT,ans);
                sort(ans.begin(),ans.end());
                res.push_back(ans);
            }
            ans.clear();
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends