class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int, int> mp;

        while (r < n) {
            mp[arr[r]]++;  // add current fruit

            // if more than 2 types, shrink window from left
            while (mp.size() > 2) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) {
                    mp.erase(arr[l]);  // remove fruit type
                }
                l++;
            }

            // update maxlen
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
