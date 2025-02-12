class Solution {
public:

    // Function to calculate the sum of digits of a number
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    // Function to find the maximum sum of two numbers with the same digit sum
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Stores max number for each digit sum
        int maximumSum = -1;

        for (int num : nums) {
            int digitSum = sumOfDigits(num);

            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maximumSum = max(maximumSum, digitSumMap[digitSum] + num);
            }

            digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
            
        }
        return maximumSum;
    }
};