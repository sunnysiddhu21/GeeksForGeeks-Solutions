//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        if(n < 3) return -1; // Handle arrays with less than 3 elements
    
        int i = 1, j = n - 2; // Start i from 1 and j from n-2
        int max = arr[0], min = arr[n - 1]; // Initialize max with the first element and min with the last element
    
        while(i<n-1){
            if(arr[i] > max){
                max = arr[i];
            }
            i++;
        }
        
        while(j>=(i-1)){
            if(arr[j] < min){
                min = arr[j];
            }
            j--;
        }
        
        if(max == min) {
            return min;
        }
        else return -1;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends