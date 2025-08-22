#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> countT, window;
        for (char c : t) countT[c]++;

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        int resL = -1, resR = -1;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.find(c) != countT.end() && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                // update result
                if ((r - l + 1) < resLen) {
                    resL = l;
                    resR = r;
                    resLen = r - l + 1;
                }

                // pop from the left
                window[s[l]]--;
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resL, resLen);
    }
};
