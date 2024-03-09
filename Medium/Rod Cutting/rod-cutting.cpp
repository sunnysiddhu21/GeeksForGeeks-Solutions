//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int j=0;j<=n;j++){
            if(j>=1 && j%1==0){
                dp[0][j] = price[0]*j;
            }
            else{
                dp[0][j] = 0;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++){
                int take = INT_MIN;
                int nottake = INT_MIN;
                
                if(j>=i+1){
                    take = price[i] +  dp[i][j-(i+1)];
                }
                
                nottake = dp[i-1][j];
                
                dp[i][j] = max(take,nottake);
            }
        }
        
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends