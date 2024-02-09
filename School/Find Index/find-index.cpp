//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int a[], int n, int key)
    {
        //code here.
        int first=-2;
        int last=-2;
        int b=1;
        for(int i=0;i<n;i++){
            if(a[i]==key){
                if(b==1){
                    first=i;
                    b=2;
                }
                last=i;
            }
        }
         vector<int>vt;
        if(last==-2 && first==-2)
        { 
            vt.push_back(-1);
            vt.push_back(-1);
            return vt;
        }
        else{
           
            vt.push_back(first);
            vt.push_back(last);
            return vt;
        }
    }
  
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends