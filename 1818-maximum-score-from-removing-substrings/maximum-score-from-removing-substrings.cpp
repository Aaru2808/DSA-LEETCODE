class Solution {
public:
    int maximumGain(string str, int val1, int val2) {
         if (val1 > val2) {
            return solve(str, 'a', 'b', val1, val2);
        } else {
            return solve(str, 'b', 'a', val2, val1);
        }
    }

    int solve(string str, char ch1, char ch2, int high, int low) {
        stack<char> stk;
        int score = 0;

        for (char ch : str) {
            if (!stk.empty() && stk.top() == ch1 && ch == ch2) {
                stk.pop();
                score += high;
            } else {
                stk.push(ch);
            }
        }

        string remaining;
        while (!stk.empty()) {
            remaining += stk.top();
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char ch : remaining) {
            if (!stk.empty() && stk.top() == ch2 && ch == ch1) {
                stk.pop();
                score += low;
            } else {
                stk.push(ch);
            }
        }

        return score;
    }
        
        
    
};