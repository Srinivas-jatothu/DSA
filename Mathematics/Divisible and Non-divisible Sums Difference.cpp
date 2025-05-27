// leetcode problem : https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;

        return n*(n+1)/2 - m * k * (k+1);
    }
};

/*
Algorithm Explanation:
1. The function `differenceOfSums` takes two integers `n` and `m` as input.
2. It calculates `k`, which is the number of multiples of `m` that are less than or equal to `n` (i.e., `k = n/m`).
3. The sum of the first `n` natural numbers is calculated using the formula `n*(n+1)/2`.
4. The sum of the first `k` multiples of `m` is calculated using the formula `m * k * (k+1)`.
5. The function returns the difference between the two sums: the sum of the first `n` natural numbers minus the sum of the first `k` multiples of `m`.
*/