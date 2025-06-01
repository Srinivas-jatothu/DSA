// leetcode problem : https://leetcode.com/problems/distribute-candies-among-children-ii/?envType=daily-question&envId=2025-06-01

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { 

            int N = n-i; 

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};



/*
Algorithm Explanation:
1. **Understanding the Problem**: We need to distribute `n` candies among 2 children such that each child can receive at most `limit` candies. The task is to count the number of valid distributions.
2. **Setting Up the Range**: 
   - For the first child, the minimum candies they can receive is `max(0, n - 2*limit)`, which ensures that the second child can still receive candies without exceeding their limit.
   - The maximum candies the first child can receive is `min(n, limit)`.
3. **Iterating Over Possible Distributions**:
    - For each possible number of candies `i` given to the first child, we calculate how many candies are left for the second child (`N = n - i`).
    - We then determine the valid range for the second child's candies, which is from `max(0, N - limit)` to `min(N, limit)`.
4. **Counting Valid Distributions**:
    - The number of valid distributions for the second child is simply the difference between the maximum and minimum values plus one.
5. **Summing Up**: We accumulate the counts for each possible distribution of candies to the first child to get the total number of valid distributions.
*/