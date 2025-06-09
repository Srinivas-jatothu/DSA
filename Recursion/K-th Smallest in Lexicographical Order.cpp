//leetcode problem : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-question&envId=2025-06-09

class Solution {
public:

    int Count(long curr, long next, int n) {
        int countNum = 0;

        while(curr <= n) {
            countNum += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, long(n+1));
        }

        return countNum;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; 

        while(k > 0) {
            int count = Count(curr, curr+1, n);
            if(count  <= k) {
                curr++;
                k -= count; 
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;

    }
};

/*
Algorithm Explanation:
1. The `findKthNumber` function initializes `curr` to 1 and decrements `k` by 1 to adjust for zero-based indexing.
2. It enters a loop that continues until `k` becomes 0.
3. Inside the loop, it calls the `Count` function to determine how many numbers exist in the range from `curr` to `curr + 1` that are less than or equal to `n`.
4. If the count is less than or equal to `k`, it means the k-th number is not in the current range, so it increments `curr` and decrements `k` by the count.
5. If the count is greater than `k`, it means the k-th number is in the current range, so it multiplies `curr` by 10 (to go deeper into the lexicographical order) and decrements `k` by 1.
6. The loop continues until `k` becomes 0, at which point `curr` will be the k-th smallest number in lexicographical order.
7. Finally, the function returns `curr`, which is the k-th smallest number in lexicographical order up to `n`.
*/