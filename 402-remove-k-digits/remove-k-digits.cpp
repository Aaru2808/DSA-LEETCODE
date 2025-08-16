class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& k>0 && st.top()>num[i] ){
                st.pop();
                k--;
            }
            if(!st.empty() || num[i] !='0' ){
                st.push(num[i]);

            }
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};