class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int  n= nums.size();
         unordered_set<int>st;
        int maxSum=0,sum=0;
        int i=0;
       
        for(int j=0;j<n;j++){
            while(st.count(nums[j])){
                sum=sum-nums[i];
                st.erase(nums[i]);
                i++;
            }
        
        sum+=nums[j];
        st.insert(nums[j]);
        
        maxSum=max(sum,maxSum);
        
    }
    return maxSum;
    }
};