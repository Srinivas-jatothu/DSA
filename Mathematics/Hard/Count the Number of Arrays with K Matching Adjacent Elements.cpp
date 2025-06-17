//leetcode problem : https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/?envType=daily-question&envId=2025-06-17

int MOD = 1e9+7;
class Solution {
public:
    int findPower(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;

        if(b%2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {
      
        return factorial[n] * fermatFact[n-r] % MOD * fermatFact[r] % MOD; 
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % MOD;
        }

        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], MOD-2);
        }

        long long result = nCr(n-1, k, factorial, fermatFact); 

        result = result * m % MOD;

        result = result * findPower(m-1, n-k-1) % MOD; 


        return result;
    }
};


/*
Algorithm Explanation:
1. **Factorial Calculation**: Precompute the factorials and their modular inverses using Fermat's Little Theorem to handle large numbers efficiently.
2. **Combination Calculation**: Use the precomputed factorials to calculate the number of ways to choose `k` positions from `n-1` using the formula for combinations (nCr).
3. **Result Calculation**:
   - Multiply the result by `m` to account for the choice of the first element.
   - Multiply by `(m-1)^(n-k-1)` to account for the choices of the remaining elements, ensuring that adjacent elements match the first element.
// 4. **Return Result**: Return the final result modulo `1e9 + 7` to ensure it fits within standard integer limits.
Time Complexity: O(n), where n is the size of the input array, due to the precomputation of factorials and their inverses.
*/