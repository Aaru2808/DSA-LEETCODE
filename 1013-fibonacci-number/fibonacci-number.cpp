class Solution {
public:
// top down approach
    // int fibo(int n,vector<int>&dp){
    //     if(n<=1)return n;
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    //     return dp[n];

    // }
    // int fib(int n) {
    //     vector<int>dp(n+1,-1);
    //     return fibo(n,dp);
        
    // }

    //bottom up appraoch
    int fib(int n){
        if(n<=1)return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];

        }
        return dp[n];
    }


};