class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (int i = 0; i < word.length(); i++) {
            char c = word[i];

            if (!isalnum(c)) return false; // if not digit or letter → invalid

            if (isalpha(c)) {
                char ch = tolower(c);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
