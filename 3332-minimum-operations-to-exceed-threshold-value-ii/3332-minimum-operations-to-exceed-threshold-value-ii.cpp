class Solution {
public:
    // Function to determine the minimum number of operations required
    int minOperations(vector<int>& nums, int k) {
        // Create a min-Heap (priority queue) and initialize it with the given numbers
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        // Contine processing until the smallest number in the heap is at least k
        while (minHeap.size() > 1 && minHeap.top() < k) {
            // Extract the two smalles elements
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            

            

            // Calculate the new element to be inserted back into the heap
            long long newElement = min(x, y) * 2 + max(x, y);
            minHeap.push(newElement);

            // Increment operation count
            operations++;
        }

        return operations;
    }
};