//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numberOfWays(int N) {
        long long dp[N+1];
        long long mod=1e9+7;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=N;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[N];
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.numberOfWays(n) << endl;
    }
    return 0;
}
// } Driver Code Ends