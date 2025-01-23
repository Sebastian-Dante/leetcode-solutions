class Solution {
public:
    bool canConstruct(string s, int k) {
        // If k is greater than the length of s, it's impossible to form k palindromes
        if (k > s.length()) {
            return false;
        }
        
        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                oddCount++;

            }
        }

        // To form k palindromes, the number of odd-frequency characters
        // must not exceed k (since each odd character requires its own palindrome)
        return oddCount <= k;
    }
};