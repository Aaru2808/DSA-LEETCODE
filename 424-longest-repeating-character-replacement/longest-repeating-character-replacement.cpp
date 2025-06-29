class Solution {
public:
    int characterReplacement(string s, int k) {
       int n= s.size();
       int i=0,j=0,maxlen=0,maxfreq=0;
       unordered_map<char,int>mp;
       while(j<n){
        mp[s[j]]++;
        maxfreq=max(maxfreq,mp[s[j]]);
        //check how many character need to be replaced
        int changes= (j-i+1)-maxfreq;
        if(changes>k){
            mp[s[i]]--;
            i++;

        }
        maxlen= max(maxlen,j-i+1);
        j++;
       }
       return maxlen;
    }
};