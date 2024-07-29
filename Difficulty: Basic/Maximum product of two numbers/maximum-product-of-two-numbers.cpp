//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    int maxProduct(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n < 2) return 0;

        int maxi = INT_MIN;
        int secMaxi = INT_MIN;
        int cnt=0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] > maxi) {
                secMaxi = maxi;
                maxi = arr[i];
            } else if (arr[i] > secMaxi && arr[i] != maxi) {
                secMaxi = arr[i];
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]==maxi){
                cnt++;
            }
        }
        
        if(cnt>=2){
            return maxi*maxi;
        }else{
            return maxi * secMaxi;
        }
        

       
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.maxProduct(arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends