// leetcode problem : https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/?envType=daily-question&envId=2025-06-27

class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};

/*
Algorithm Explanation:
1. Count the frequency of each character in the string `s`.
2. Create a vector `canUse` to track which characters can be used in the subsequence based on their frequency.
3. Create a vector `requiredFreq` to store how many times each character can be used in the subsequence.
4. Use backtracking to explore all possible subsequences:
   - If the current subsequence length exceeds the maximum allowed length, return.
   - If the current subsequence is valid (i.e., it can be formed `k` times from `s`), update the result if it's longer or lexicographically larger than the previous result.
   - For each character that can be used, add it to the current subsequence, decrement its required frequency, and recursively explore further.
   - After exploring, backtrack by removing the last character and restoring its frequency.
5. The function returns the longest subsequence that can be formed `k` times from `s`.
6. The time complexity is O(26^k * n) in the worst case, where `n` is the length of the string `s` and `k` is the number of times the subsequence should be repeated. The space complexity is O(n) for storing the result and the current subsequence.

*/