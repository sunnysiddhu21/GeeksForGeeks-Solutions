//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>>
        maxHeap;
        vector<int> res;
        
        for(int num: nums){
            freq[num]++;
            
        }
        for (auto it : freq) {
            maxHeap.push({it.second, it.first});
            
        }
        while (k--){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
        // Code here
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends