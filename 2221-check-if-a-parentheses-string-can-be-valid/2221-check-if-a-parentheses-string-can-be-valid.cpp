class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // A valid parantheses string must have even length

        int minOpen = 0, maxOpen = 0;
        // Left to right pass to check if we can have enough '('
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                maxOpen++;
            } else {
                maxOpen--;
            }
            if (s[i] == ')' || locked[i] == '0') {
                minOpen--;
            } else {
                minOpen++;
            }
            if (maxOpen < 0) return false; // Too many ')'
            minOpen = max(0, minOpen);
            
        }

        minOpen = 0, maxOpen = 0;
        // Right to left pass: Track possible ')' count range
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                maxOpen++;
            } else {
                maxOpen--;
            }
            if (s[i] == '(' || locked[i] == '0') {
                minOpen--;
            } else {
                minOpen++;
            }
            if (maxOpen < 0) return false; // Too many '('
            minOpen = max(0, minOpen); // minOpen cannot be negative
        }

        return true; 
    }
};