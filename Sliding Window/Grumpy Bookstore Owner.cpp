// leetcode problem : https://leetcode.com/problems/grumpy-bookstore-owner/description/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;

        // Calculate initial unsatisfied customers in the first 'minutes' window
        for (int i = 0; i < minutes; i++) {
            unsat += customers[i] * grumpy[i];
        }

        int maxUnsat = unsat;

        // Use two pointers i and j to define the sliding window of size 'minutes'
        int i = 0;
        int j = minutes;

        while(j < n) {
            unsat += customers[j] * grumpy[j];             // Include current element
            unsat -= customers[i] * grumpy[i];             // Remove element going out of window
            
            maxUnsat = max(maxUnsat, unsat);               // Update maxUnsat
            i++;
            j++;
        }

        int totalCustomers = maxUnsat;

        // Calculate total satisfied customers
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        return totalCustomers;
    }
};


/*
Algorithm Explanation:
1. Initialize `unsat` to count the number of unsatisfied customers in the first `minutes` window.
2. Use a sliding window approach with two pointers `i` and `j`:
   - `i` represents the start of the window, and `j` represents the end of the window.
   - For each new position of `j`, add the unsatisfied customers at `j` and remove those at `i`.
   - Update `maxUnsat` with the maximum number of unsatisfied customers found in any window.
3. Calculate the total number of satisfied customers by adding the unsatisfied customers in the best window to those who are satisfied regardless of grumpiness.
4. Return the total number of satisfied customers.  
Time Complexity: O(n), where n is the number of customers.
Space Complexity: O(1), as we are using a constant amount of extra space.
*/