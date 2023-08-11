//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r, int c,vector<vector<int>>&vis,vector<pair<int,int>>&vec,vector<vector<int>>&grid, int r0, int c0)
  {
      vis[r][c]=1;
      vec.push_back({r-r0,c-c0});
      int delRow[]={-1,0,1,0};
      int delCol[]={0,1,0,-1};
      int n=grid.size();
      int m=grid[0].size();
      for(int i=0;i<4;i++)
      {
          int nrow=r+delRow[i];
          int ncol=c+delCol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
          dfs(nrow,ncol,vis,vec,grid,r0,c0);
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,vec,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends