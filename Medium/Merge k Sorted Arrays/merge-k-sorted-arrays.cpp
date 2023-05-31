//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class data{
    public:
    int num,apos,numpos;
    public:
    data(int num,int apos,int numpos)
    {
        this->num=num;
        this->apos=apos;
        this->numpos=numpos;
    }
};
class Solution
{
    struct comp{
        bool operator()(data d1,data d2)
        {return d1.num>d2.num;
        }
    };
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k )
    {
        vector<int>ans;
        priority_queue<data,vector<data>,comp>pq;
        for(int i=0;i<k;i++)
        {
            data ds(arr[i][0],i,0);
            pq.push(ds);
        }
        while(!pq.empty())
        {
            data it=pq.top();
            pq.pop();
            int num=it.num;
            int apos=it.apos;
            int numpos=it.numpos;
            
            ans.push_back(num);
            if(numpos+1<arr[apos].size())
            {
                data ds(arr[apos][numpos+1],apos,numpos+1);
                pq.push(ds);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends