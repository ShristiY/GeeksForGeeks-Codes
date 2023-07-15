//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        vector<int>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        set<pair<int,int>>st;
        int sum=A[N-1]+B[N-1];
        pq.push({sum,{N-1,N-1}});
        st.insert({N-1,N-1});
        
        while(k>0)
        {
            k--;
            auto it=pq.top();
            int sum=it.first;
            int L=it.second.first;
            int R=it.second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            if(L>0 && st.find({L-1,R})==st.end())
            {
                pq.push({A[L-1]+B[R],{L-1,R}});
                st.insert({L-1,R});
            }
            if(R>0 && st.find({L,R-1})==st.end())
            {
                pq.push({A[L]+B[R-1],{L,R-1}});
                st.insert({L,R-1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends