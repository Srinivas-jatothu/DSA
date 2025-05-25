// leetcode problem : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for(string &word : words) {
            string reversedWord = word;
            swap(reversedWord[0], reversedWord[1]);

            if(mp[reversedWord] > 0) {
                result += 4;
                mp[reversedWord]--;
            } else {
                mp[word]++;
            }
        }

        for(auto &it : mp) {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};


/*
Algorithm explanation:
1. Initialize an unordered map `mp` to keep track of the count of each two-letter word.
2. Initialize an integer `result` to 0, which will store the length of the longest palindrome.
3. Loop through each word in the `words` vector:
   - Create a `reversedWord` by swapping the two characters of the current word.
   - If `reversedWord` exists in the map with a count greater than 0, it means we can form a palindrome with this word and its reverse. Increment `result` by 4 and decrement the count of `reversedWord` in the map.
   - If not, increment the count of the current `word` in the map.
4. After processing all words, check the map for any two-letter word that is a palindrome (i.e., both characters are the same). If such a word exists and its count is greater than 0, increment `result` by 2 and break the loop.
5. Finally, return the `result`, which represents the length of the longest palindrome that can be formed by concatenating two-letter words.
// Time complexity: O(n), where n is the number of words in the input vector.
*/