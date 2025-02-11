class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        vector<int> diffIndices;
        for ( int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        // There must be exactly two indices where characters differ
        if (diffIndices.size() != 2) return false;

        // Swap should make the strings equal
        int i = diffIndices[0], j = diffIndices[1];
        swap(s2[i], s2[j]); // Perform swap in s2
        return s1 == s2; // Check if they become equal
    }
};