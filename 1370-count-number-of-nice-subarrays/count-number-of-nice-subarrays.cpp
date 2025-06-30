class Solution {
public:
    int atMostKOdds(vector<int>& nums, int k) {
        int l = 0, count = 0, odds = 0;

        for (int r = 0; r < nums.size(); r++) {
            odds += nums[r] % 2;

            while (odds > k) {
                odds -= nums[l] % 2;
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOdds(nums, k) - atMostKOdds(nums, k - 1);
    }
};
