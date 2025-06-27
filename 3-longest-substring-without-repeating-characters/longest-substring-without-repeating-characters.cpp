class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int i=0,j=0, maxLen=1;
        int n= s.size();
        unordered_map<char,int>mp;
        while(j<n){
            if(mp.find(s[j])!=mp.end() && mp[s[j]] >=i){
                i = mp[s[j]]+1;

            }
            maxLen= max(maxLen,j-i+1);
            mp[s[j]]=j;
            j++;

        }
        return maxLen;
        
        
    }
};