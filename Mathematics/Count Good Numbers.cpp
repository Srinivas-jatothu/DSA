//leetcode problem : https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13


class Solution {
    public:
        const int M = 1e9+7;
        int findPower(long long a, long long b) {
            if(b == 0) {
                return 1;
            }   
            long long half = findPower(a, b/2);
            long long result = (half * half) % M;
            if(b % 2 == 1) {
                result = (result * a) % M;
            }
            return result;
        }
        int countGoodNumbers(long long n) {
            return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
        }
    };



    /*
    
    Algorithm explanation:
    1. The function `findPower` calculates the power of a number `a` raised to `b` using recursion and modular arithmetic.
    2. The base case is when `b` is 0, in which case it returns 1.
    3. It calculates the half power recursively and squares it to get the result.
    4. If `b` is odd, it multiplies the result by `a` to account for the extra factor.
    5. The `countGoodNumbers` function calculates the number of good numbers based on the given formula.
    6. It uses the `findPower` function to compute the powers of 5 and 4, which represent the number of choices for even and odd positions respectively.
    7. The final result is obtained by multiplying the two powers and taking the modulo with `M` (1e9 + 7).
    8. The function returns the final count of good numbers.
    9. The time complexity of the algorithm is O(log n) due to the recursive power calculation.
    */
