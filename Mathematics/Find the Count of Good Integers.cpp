//leetcode problem : https://leetcode.com/problems/find-the-count-of-good-integers/?envType=daily-question&envId=2025-04-12


class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> st;
    
            int d = (n+1)/2;
            int start = pow(10, d-1);
            int end   = pow(10, d) - 1;
    
            for(int num = start; num <= end; num++) {
                string leftHalf = to_string(num);
                string full = "";
    
                if(n%2 == 0) {
                    string rightHalf = leftHalf;
                    reverse(rightHalf.begin(), rightHalf.end());
                    full = leftHalf + rightHalf;
                } else {
                    string rightHalf = leftHalf.substr(0, d-1);
                    reverse(rightHalf.begin(), rightHalf.end());
                    full = leftHalf + rightHalf;
                }
    
                long long number = stoll(full);
                if(number % k != 0)
                    continue;
                
                sort(full.begin(), full.end());
                st.insert(full);
            }
    
            vector<long long> factorial(11, 1);
            for(int i = 1; i < 11; i++) {
                factorial[i] = factorial[i-1] * i;
            }
            long long result = 0;
            for(const string &s : st) {
                vector<int> count(10, 0);
                for(const char &ch : s) {
                    count[ch - '0']++; //mp[ch]++
                }
    
                int totalDigits = s.length();
                int zeroDigits = count[0];
                int nonZeroDigits = totalDigits - zeroDigits;
    
                long long perm = (nonZeroDigits * factorial[totalDigits-1]);
    
                for(int i = 0; i < 10; i++) {
                    perm /= factorial[count[i]];
                }
    
                result += perm;
            }
    
            return result;
        }
    };




    /*
    Algorithm Explanation:
    1. The function `countGoodIntegers` takes two integers `n` and `k` as input, representing the number of digits and the divisor respectively.
    2. It initializes an unordered set `st` to store unique good integers.
    3. It calculates `d`, which is half of `n` (rounded up), and determines the range of numbers to check for symmetry.
    4. It iterates through each number `num` in the range from `start` to `end`, where `start` is the smallest number with `d` digits and `end` is the largest number with `d` digits.
    5. For each number, it constructs the full integer by concatenating the left half and the right half (or its reverse) based on whether `n` is even or odd.
    6. It checks if the full integer is divisible by `k`. If not, it continues to the next iteration.
    7. It sorts the digits of the full integer and inserts it into the set `st` to ensure uniqueness.
    8. It precomputes the factorial values for digits from 0 to 10 to facilitate the calculation of permutations.
    9. It initializes a variable `result` to store the total count of good integers.
    10. For each unique string `s` in the set `st`, it counts the occurrences of each digit and calculates the total number of permutations.
    11. It handles the case where the first digit is zero separately to avoid leading zeros.
    12. It calculates the number of permutations using the formula for permutations of multiset and adds it to the result.
    13. Finally, it returns the total count of good integers found.
    */