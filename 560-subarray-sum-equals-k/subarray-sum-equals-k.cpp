class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            if(sum==k)count++;
            if(mp.find(sum-k)!=mp.end()){
                count=mp[sum-k]+count;

            }
            if(mp.find(sum)!=mp.end()){
                mp[sum]++;

            }else{
                mp[sum]=1;
            }
            
        }
        return count;
    }
};