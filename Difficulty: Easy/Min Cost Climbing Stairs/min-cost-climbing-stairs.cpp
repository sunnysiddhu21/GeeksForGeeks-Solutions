//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    
    int minCost(int ind,vector<int>&cost,vector<int> &dp){
        if(ind<=1) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=cost[ind]+min(minCost(ind-1,cost,dp),minCost(ind-2,cost,dp));
    }
  
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        //Write your code here
        vector<int> dp(n+1,-1);
        return min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends