// leetcode problem : https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/?envType=daily-question&envId=2025-04-22

class Solution {
    public:
        int M = 1e9+7;
        void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {
            if(dp[m][1] != 0) {
                return;
            }
    
            dp[m][1] = 1;
            count[1]++;
    
            for(int div = 2; div <= m; div++) {
                if(m % div == 0) {
                    findSets(m/div, count, dp);
    
                    for(int len = 1; len < 15; len++) {
                        if(dp[m/div][len] != 0) {
                            dp[m][len+1] += dp[m/div][len];
                            count[len+1] += dp[m/div][len];
                        }
                    }
                }
            }
        }
    
        int findPower(long long a, long long b) {
            if(b == 0)
                return 1;
            
            long long half = findPower(a, b/2);
            long long result = (half * half) % M;
    
            if(b%2 == 1) {
                result = (result * a) % M;
            }
    
            return result;
        }
    
        int modularnCr(int n, int r, vector<long long>& fact) {
            if(r < 0 || r > n)
                return 0;
            
            long long b = (fact[r] * fact[n-r]) % M;
            return (fact[n] * findPower(b, M-2)) % M;
        }
    
        int idealArrays(int n, int maxVal) {
            vector<vector<int>> dp(maxVal+1, vector<int>(15, 0));
            vector<int> count(15, 0);
    
            //Find sets count
            for(int val = 1; val <= maxVal; val++) {
                findSets(val, count, dp);
            }
    
            //Precompute factorials
            vector<long long> fact(n+1, 1);
            for(int i = 2; i <= n; i++) {
                fact[i] = (fact[i-1] * i) % M;
            }
    
            long long result = 0;
            for(int len = 1; len < 15; len++) {
                if(n < len) {
                    break;
                }
                if(count[len] != 0) {
                    long long possibilities = modularnCr(n-1, len-1, fact);
                    result = (result + (count[len] * possibilities)%M) % M;
                }
            }
    
            return (int)result;
    
        }
    };

    


    /*
    Algorithm explanation:
    1. The function idealArrays takes two integers n and maxVal as input, where n is the size of the array and maxVal is the maximum value allowed in the array.
    2. It initializes a constant M to 1e9+7, which is used for modular arithmetic.
    3. It defines a helper function findSets that takes an integer m, a vector count, and a 2D vector dp as input.
    4. This function is used to find the number of sets of integers that can be formed with the given constraints.
    5. It initializes dp[m][1] to 1 and increments count[1].
    6. It then iterates through all divisors of m and recursively calls findSets for each divisor.
    7. For each divisor, it updates the dp and count vectors based on the results of the recursive call.
    8. The function findPower calculates the power of a number a raised to b using modular exponentiation.
    9. It handles the case when b is 0 and uses recursion to calculate the result efficiently.
    10. The function modularnCr calculates the binomial coefficient nCr using precomputed factorials and modular arithmetic.
    11. It checks if r is valid and calculates the result using the formula n! / (r! * (n-r)!).
    12. The function idealArrays initializes a 2D vector dp and a vector count to store the number of sets.
    13. It calls findSets for each value from 1 to maxVal to populate the dp and count vectors.
    14. It precomputes the factorials up to n and stores them in the fact vector.
    15. It initializes a variable result to 0.
    16. It iterates through the count vector and calculates the number of valid arrays for each length.
    17. It uses the modularnCr function to calculate the number of possibilities for each length and adds it to the result.
    18. Finally, it returns the result modulo M.
    19. The algorithm efficiently calculates the number of ideal arrays using dynamic programming and modular arithmetic.
    20. The time complexity of this algorithm is O(n * log(maxVal)), where n is the size of the array and maxVal is the maximum value allowed in the array.
    21. The space complexity is O(maxVal) for the dp and count vectors.
    */