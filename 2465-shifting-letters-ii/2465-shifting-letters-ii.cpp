class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shiftDiff(n + 1, 0);

        // Process the shifts
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1: -1;
            shiftDiff[start] += delta;
            shiftDiff[end + 1] -= delta;
        }

        // Calculate prefix sum to determine the total shift for each character
        vector<int> totalShifts(n, 0);
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftDiff[i];
            totalShifts[i] = cumulativeShift;
        }

        // Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = totalShifts[i] % 26;
            if (shift < 0) {
                shift += 26; // Ensure positive shift for backward shifts
            }
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
        
    }
};