// leetcode problem : https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08

class Solution {
public:
    void solve(int curr, int n, vector<int>& res) {
        if (curr > n) return;
        res.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            int next = curr * 10 + i;
            if (next > n) return;
            solve(next, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            if (i > n) break;
            solve(i, n, res);
        }
        return res;
    }
};



/*
Algorithm Explanation:
1. The `lexicalOrder` function initializes an empty vector `res` to store the result.
2. It iterates through numbers from 1 to 9, calling the `solve` function for each number.
3. The `solve` function takes the current number `curr`, the upper limit `n`, and the result vector `res`.
4. If `curr` exceeds `n`, it returns immediately.
5. Otherwise, it adds `curr` to `res`.
6. It then generates the next numbers by appending digits from 0 to 9 to `curr` and recursively calls itself with the new number.
7. This process continues until all valid numbers in lexicographical order up to `n` are added to `res`.
8. Finally, the `lexicalOrder` function returns the result vector `res`, which contains the numbers in lexicographical order.

*/