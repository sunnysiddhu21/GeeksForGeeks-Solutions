//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i < V+1; i++)
                list.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int c = sc.nextInt();
            int d = sc.nextInt();
            
            Solution ob = new Solution();
            
            System.out.println(ob.isBridge(V,list,c,d));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution
{   
    
    static int timer=1;
    static boolean dfs(int node,int parent,int c,int d,boolean[]vis,int []time, int low[] , ArrayList<ArrayList<Integer>> adj )
    {
        vis[node]=true;
        time[node] = low[node]=timer;
        timer++;
        
        for(int it:adj.get(node)){
            if(parent==it)continue;
            
            
            if(!vis[it]){
                if(dfs(it,node,c,d,vis,time,low,adj)==true){
                    return true;
                }
                
                low[node] = Math.min(low[it],low[node]);
                
                if(low[it]>time[node]  && ((node == c && it==d) || (node ==d && it==c))){
                  return true;
                }
            }
            else{
                low[node] =  Math.min(low[it],low[node]);
            }
        }
        return false ;
    }
    
    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj,int c,int d)
    {
        // code here
        boolean vis[] = new boolean[V];
        int time [] = new int[V];
        int low [] = new int[V];
        
       
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,c,d,vis,time,low,adj)){
                   return 1;
                }
            }
        }
        return 0;
    }
}