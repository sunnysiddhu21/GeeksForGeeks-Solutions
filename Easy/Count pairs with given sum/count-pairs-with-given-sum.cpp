//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int nums[], int n, int target) {
        // code here
         
         int result=0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            if(mp.find(target-nums[i])!=mp.end()){
                result+=mp[target-nums[i]];
            }
            mp[nums[i]]++;
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends