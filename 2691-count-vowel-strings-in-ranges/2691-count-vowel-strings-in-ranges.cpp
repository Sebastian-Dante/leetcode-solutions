#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Helper function to check if a word starts and ends with vowels
        auto isValid = [&vowels](const string& word) {
            return vowels.count(word.front()) && vowels.count(word.back());
        };

        // Precompute prefix sums
        int n = words.size();
        vector<int> prefix(n, 0);
        prefix[0] = isValid(words[0]) ? 1 : 0;

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (isValid(words[i]) ? 1 : 0);
        }

        // Answer each query using the prefix sum
        vector<int> ans;
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            if (li == 0) {
                ans.push_back(prefix[ri]);
            } else {
                ans.push_back(prefix[ri] - prefix[li - 1]);
            }
        }

        return ans;
    }
};