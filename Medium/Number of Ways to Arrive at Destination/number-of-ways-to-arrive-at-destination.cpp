//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            // {u, v, w}
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> weight(n, 1e15);
        vector<int> way(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        weight[0] = 0;
        way[0] = 1;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if (node == n - 1)
            {
                break;
            }
            for (auto &&neighbour : adj[node])
            {
                int newnode = neighbour.first;
                long long newdist = neighbour.second;

                if (newdist + dist < weight[newnode])
                {
                    weight[newnode] = newdist + dist;
                    way[newnode] = way[node];
                    pq.push({newdist + dist, newnode});
                }
                else if (newdist + dist == weight[newnode])
                {
                    way[newnode] = (way[newnode] + way[node] * 1LL) % mod;
                }
            }
        }
        return way[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends