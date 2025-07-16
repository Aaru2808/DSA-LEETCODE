class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        int evenCount=0;
        int oddCount=0;
      
        for(auto &num:nums){
            if(num%2==0){
               evenCount++;
            }
            else{
                oddCount++;
        }
        }
        int parity=nums[0]%2;
        int alternate=1;
        for(int i=0;i<n;i++){
            int currParity=nums[i]%2;
            if(parity != currParity){
                alternate++;
                parity=currParity;
            }

        }
        return max({oddCount,evenCount,alternate});


    }
};