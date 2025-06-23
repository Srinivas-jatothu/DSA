// leetcode problem : https://leetcode.com/problems/sum-of-k-mirror-numbers/description/?envType=daily-question&envId=2025-06-23

class Solution {
public:
    
    bool isPalindrome(string baseK) {
        int i = 0;
        int j = baseK.length()-1;

        while(i <= j) {
            if(baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string convertToBaseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string res = "";
        while(num > 0) {
            res += to_string(num%k);
            num /= k;
        }

        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; //create L length palindromes

        while(n > 0) {
            int half_length = (L+1)/2;
            
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if(L % 2 == 0) { //even length palindrome
                    pal = first_half + second_half;
                } else { //off length palindrome
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPalindrome(baseK)) {
                    sum += pal_num; //found one k-mirror number
                    n--;
                    if(n == 0) {
                        break;
                    }
                }
            }

            L++;
        }

        return sum;
    }
};


/*
Algorithm Explanation:
1. **isPalindrome**: This function checks if a given string is a palindrome by comparing characters from both ends towards the center.
2. **convertToBaseK**: This function converts a number to its representation in base `k`. It repeatedly divides the number by `k` and collects the remainders, which represent the digits in base `k`.
3. **kMirror**: This is the main function that calculates the sum of the first `n` k-mirror numbers.
   - It initializes the sum to 0 and starts with a length `L` of 1 for the palindromes.
   - It continues generating palindromes until it finds `n` k-mirror numbers.
   - For each length `L`, it calculates the minimum and maximum numbers that can form half of the palindrome.
   - It constructs palindromes by mirroring the first half and checks if their base `k` representation is a palindrome.
   - If it finds a valid k-mirror number, it adds it to the sum and decrements `n`.
   - The process continues until `n` reaches 0.
// Time Complexity: O(n * k^L) where n is the number of k-mirror numbers to find, k is the base, and L is the length of the palindromes.
// Space Complexity: O(L) for storing the palindrome and base k representations.
*/