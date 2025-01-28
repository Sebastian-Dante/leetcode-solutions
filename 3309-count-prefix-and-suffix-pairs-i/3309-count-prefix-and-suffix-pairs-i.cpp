class Solution {
public:

    // Function to check if str1 is both a prefix and a suffix of str2
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        // Check if str1 can be both a prefix and a suffix of str2
        if (n1 > n2) return false;

        return str2.substr(0, n1) == str1 && str2.substr(n2 - n1) == str1;
    }

    // Function to count the number of valid index pairs (i, j)

    int countPrefixSuffixPairs(const vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
        
    }
};