//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M, int x, int y,int n){
        if(M[x][y]==1)
        return true;
        else
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> a;
       for(int i=0; i<n ;i++){
           a.push(i);
       }
       
       //step2:
       while(a.size() > 1){
           int x = a.top();
           a.pop();
           
           int y = a.top();
           a.pop();
           
           if(knows(M,x,y,n)){
               a.push(y);
           }
           else{
               a.push(x);
           }
       }
       int res = a.top();
       //step3
       
       bool rowCheck = false;
       
       int zeroCount = 0;
       
       for(int i=0;i<n;i++){
           if(M[res][i]==0)
           zeroCount++;
       }
       if(zeroCount == n)
       {
           rowCheck = true;
       }
       
       bool colCheck = false;
       
       int oneCount = 0;
         for(int i=0;i<n;i++){
           if(M[i][res]==1)
           oneCount++;
       }
       if(oneCount == n-1)
       {
           colCheck = true;
       }
       
       if(rowCheck == true && colCheck == true){
           return res;
       }
       else
       {
           return -1;
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends