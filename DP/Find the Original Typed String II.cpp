// leetcode problem : https://leetcode.com/problems/find-the-original-typed-string-ii/?envType=daily-question&envId=2025-07-02

class Solution {
public:
    int M = 1e9+7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {

            vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }
                
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;
    }
};



/*
Algorithm Explanation:
1. The function `possibleStringCount` takes a string `word` and an integer `k` as input.
2. It checks if `k` is greater than the length of `word`. If so, it returns 0 since it's not possible to form a string of length `k`.
3. It initializes a vector `freq` to store the frequency of consecutive characters in `word`.
4. It iterates through the string `word` to count the frequency of consecutive characters and stores them in the `freq` vector.
5. It calculates the total possible strings `P` by multiplying the frequencies in `freq` and taking modulo `M`.
6. If the size of `freq` is greater than or equal to `k`, it returns `P` as the result since there are enough frequencies to form a string of length `k`.
7. It initializes a 2D vector `t` to store the number of ways to form strings of length `k` using the frequencies in `freq`.
8. It fills the last row of `t` with 1s for all counts less than `k`, as there is one way to form a string of length `k` using no frequencies.
9. It iterates through the frequencies in reverse order and calculates the number of ways to form strings of length `k` using the frequencies in `freq`.
10. It uses a prefix sum array to efficiently calculate the number of ways to form strings of length `k` for each frequency.
11. Finally, it calculates the invalid count of strings that cannot be formed and returns the result    by subtracting the invalid count from the total possible strings `P`, ensuring the result is non-negative by taking modulo `M`.
Time Complexity: O(n * k), where n is the number of unique frequencies and k is the input integer.
Space Complexity: O(n * k), where n is the number of unique frequencies and k is the input integer.
*/