// leetcode problem : https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for(char &ch : word) {
            freq[ch-'a']++;
        }

        sort(begin(freq), end(freq));

        int result           = INT_MAX;
        int deleted_till_now = 0;

        for(int i = 0; i < 26; i++) {

            int minFreq = freq[i];
            int temp    = deleted_till_now; //temp taken to find deletion for j = 25 to j > i

            for(int j = 25; j > i; j--) {
                if(freq[j] - freq[i] <= k) 
                    break;
                
                temp += freq[j] - minFreq - k;
            }

            result = min(result, temp);
            deleted_till_now += minFreq;

        }

        return result;
    }
};


/*
Algorithm Explanation:
1. Initialize a frequency vector `freq` of size 26 to count occurrences of each character in the input string `word`.
2. Iterate through each character in `word` and update the corresponding index in `freq` to count the frequency of each character.
3. Sort the `freq` vector in ascending order to process characters from least frequent to most frequent.
4. Initialize `result` to `INT_MAX` to keep track of the minimum deletions required, and `deleted_till_now` to 0 to count deletions made so far.
5. Iterate through the `freq` vector:
   - For each character frequency at index `i`, store its value in `minFreq`.
   - Initialize a temporary variable `temp` to `deleted_till_now` to calculate deletions for characters with frequencies greater than `minFreq`.
   - For each character frequency from the end of the vector (index 25) down to index `i`, check if the difference between the current frequency and `minFreq` is less than or equal to `k`. If so, break out of the loop.
   - If the difference exceeds `k`, add the excess deletions required to `temp`.
6. Update `result` with the minimum value between the current `result` and `temp`.
7. Update `deleted_till_now` by adding `minFreq` to account for the deletions made for the current character.
8. After processing all characters, return `result`, which contains the minimum deletions required to make the string k-special.
// Time Complexity: O(n log n) due to sorting the frequency vector, where n is the length of the input string.
*/