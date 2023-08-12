//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int func(int index,int *arr,vector<int>&dp)
	{
	    if(dp[index]!=-1) return dp[index];
	    if(index==0) return arr[index];
	    
	    if(index<0) return 0;
	    
	    int pick=INT_MIN;
	       
	        pick=arr[index]+func(index-2,arr,dp);
	        int notPick=0+func(index-1,arr,dp);
	   
	    return dp[index]= max(pick,notPick);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n,-1);
	   return func(n-1,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends