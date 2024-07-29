//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int isGoodorBad(string S) {
        // code here
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowels = 5;
        int maxConsonants = 3;
        int vowelCnt=0;
        int consCnt=0;
        
        for (char ch : S) {
            if (vowels.count(ch)) {
                vowelCnt++;
                consCnt = 0;
            } else if (ch == '?') {
                vowelCnt++;
                consCnt++;
            } else {
                consCnt++;
                vowelCnt = 0;
            }
            
            if (vowelCnt > maxVowels || consCnt > maxConsonants) {
                return 0;  // "BAD"
            }
        }
    
        return 1; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends