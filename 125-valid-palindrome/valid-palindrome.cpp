class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            // Move i to the next alphanumeric character
            while (i < j && !isalnum(s[i])) i++;

            // Move j to the previous alphanumeric character
            while (i < j && !isalnum(s[j])) j--;

            // Compare the lowercase versions of the characters
            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};

