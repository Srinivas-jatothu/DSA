// leetcode problem : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/?envType=daily-question&envId=2025-05-16

class Solution {
public:
    bool checkhammingDistanceOne(string &s1, string &s2) {
        int diff = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
            }
            if(diff > 1) {
                return false; 
            }
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); 
        vector<int> parent(n, -1);
        int longestSub = 1;
        int longestSubIdx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i-1; j++) {
                if(groups[j] != groups[i] && words[i].length() == words[j].length() &&
                    checkhammingDistanceOne(words[i], words[j])) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            parent[i] = j;
                            if(longestSub < dp[i]) {
                                longestSub = dp[i];
                                longestSubIdx = i;
                            }
                        }
                }
            }
        }
        vector<string> result;
        while(longestSubIdx != -1) {
            result.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }
        reverse(begin(result), end(result)); 
        return result;

    }
};

/*
Algorithm Explanation:
1. Initialize a vector dp to keep track of the length of the longest subsequence ending at each index.
2. Initialize a vector parent to keep track of the previous index in the longest subsequence.
3. Initialize variables longestSub and longestSubIdx to keep track of the length and index of the longest subsequence.
4. Iterate through the words and for each word, iterate through the previous words to check if they can form a subsequence.
5. If the current word and the previous word have different groups and the same length, and their Hamming distance is 1, update the dp and parent vectors.
6. If the length of the subsequence ending at the current word is greater than the longest subsequence found so far, update longestSub and longestSubIdx.
7. After iterating through all the words, backtrack using the parent vector to get the longest subsequence.
8. Reverse the result vector to get the correct order of the longest subsequence.
9. Return the result vector containing the longest subsequence of unequal adjacent groups.
10. The time complexity of this algorithm is O(n^2), where n is the number of words, as we are iterating through the words in a nested loop.
*/