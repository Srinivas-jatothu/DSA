// leetcode problem :  https://leetcode.com/problems/count-number-of-balanced-permutations/?envType=daily-question&envId=2025-05-09

class Solution {
public:
    int n;
    int totalDigitSum;
    int M = 1e9 + 7;
    long long totalPermPossible = 0;

    //Binary exponentian
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

    int solve(int digit, int evenIndexDigitsCount, int currSum, 
            vector<int>& freq, vector<long long>& fermatFact, 
            vector<vector<vector<int>>> &t) {
        if(digit == 10) {
            if(currSum == totalDigitSum/2 && evenIndexDigitsCount == (n+1)/2) {
                return totalPermPossible;
            }
            return 0;
        }

        if(t[digit][evenIndexDigitsCount][currSum] != -1) {
            return t[digit][evenIndexDigitsCount][currSum];
        }
        long long ways = 0;

        for(int count = 0; count <= min(freq[digit], (n+1)/2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount  = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M;

            long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n   = num.length();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i = 0; i < n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if(totalDigitSum % 2 != 0) {
            return 0;
        }

        //Precomputing factorial
        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        //Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;

        int digit = 0;
        int evenIndexDigitsCount = 0;
        int currSum = 0;
        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
        return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, t);

    }
};


/*
Algorithm Explanation:
1. The function `countBalancedPermutations` takes a string `num` as input, representing the digits of the number.
2. It initializes the length of the string `n` and calculates the total digit sum.
3. It creates a frequency vector `freq` to count the occurrences of each digit from 0 to 9.
4. It checks if the total digit sum is odd; if so, it returns 0 as there can't be a balanced permutation.
5. It precomputes the factorials and their modular inverses (Fermat's factorial) for efficient calculations.
6. It initializes the total permutations possible using the factorials of half the digits.
7. It defines a recursive function `solve` to calculate the number of balanced permutations.
8. The `solve` function uses memoization to store results for previously computed states.
9. It iterates through the digits and their counts, calculating the number of ways to form balanced permutations.
10. It returns the total number of balanced permutations modulo `M`.
11. The main function returns the result of the `solve` function.
12. The algorithm uses dynamic programming and combinatorial counting to efficiently compute the result.
13. The time complexity is O(n^2) due to the nested loops and memoization, and the space complexity is O(n) for storing the frequency and factorial arrays.
// 14. The algorithm is efficient for large inputs, making it suitable for competitive programming and interview scenarios.
*/