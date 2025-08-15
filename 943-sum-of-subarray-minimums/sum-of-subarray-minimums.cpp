class Solution {
public:
    //int sumSubarrayMins(vector<int>& arr) {
       // const long long MOD=1000000007LL;
        //time complexity is n^2//give TLE
        //  int n=(int) arr.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     int mini =arr[i];
        //     for(int j=i;j<n;j++){
        //         mini = min(mini,arr[j]);
        //         sum=(sum+mini)%MOD;

        //     }
        // }
        // return (int)sum;
        //.............................................
        
        
        
        vector<int>getNSL(vector<int>&arr,int  n){
            vector<int>result(n);
            stack<int>st;
            for(int  i=0;i<n;i++){
                if(st.empty()){
                    result[i]=-1;

                }else{
                    while(!st.empty()&& arr[st.top()]>=arr[i])
                    st.pop();
                    result[i]=st.empty()? -1: st.top();

                }
                st.push(i);
            }
            return result;
        }
        
        vector<int>getNSR(vector<int>&arr,int n){
            vector<int>result(n);
            stack<int>st;
            for(int  i=n-1;i>=0;i--){
                if(st.empty()){
                    result[i]=n;

                }else{
                    while(!st.empty()&& arr[st.top()]>arr[i])
                    st.pop();
                    result[i]=st.empty()? n: st.top();

                }
                st.push(i);
            }
            return result;
        }
        
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int>NSL=getNSL(arr,n);
            vector<int>NSR=getNSR(arr,n);
            long long sum=0;
            int M= 1e9 + 7;
            for(int i=0;i<n;i++){
                long long ls=i-NSL[i];
                long long rs=NSR[i]-i;
                long long totalways = ls*rs;
                long long totalsum=arr[i]*totalways;
                sum=(sum + totalsum)%M;

            }
            return sum;


        
    }
};