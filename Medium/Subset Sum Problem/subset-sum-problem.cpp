//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool func(int ind,int k, vector<int>&arr,vector<vector<int>>&dp)
{
    if(k==0) return true;
    if(ind==0)
    {
        if(k==arr[ind]) return true;
        return false;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool take=false;
    if(k>=arr[ind])
    take=func(ind-1,k-arr[ind],arr,dp);
    bool notTake=func(ind-1,k,arr,dp);
    return dp[ind][k]=take||notTake;
}
    bool isSubsetSum(vector<int>&arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends