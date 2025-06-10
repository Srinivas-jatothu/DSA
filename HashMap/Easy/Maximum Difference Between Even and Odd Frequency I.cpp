// leetcode problem : https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10

class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;

        for (auto& p : mp) {
            if ((p.second > maxFreq )&& (p.second%2!=0)) maxFreq = p.second;
            if ((p.second < minFreq)&& (p.second%2==0)) minFreq = p.second;
        }

        return maxFreq - minFreq;
    }
};



/*
Algorithm Explanation:
1. Initialize a map to count the frequency of each character in the string.
2. Iterate through the string and populate the frequency map.
3. Initialize variables to track the maximum frequency of characters with odd frequency and the minimum frequency of characters with even frequency.
4. Iterate through the frequency map:
   - If the frequency is odd and greater than the current maximum, update the maximum.
   - If the frequency is even and less than the current minimum, update the minimum.
5. Return the difference between the maximum odd frequency and the minimum even frequency.
// Time Complexity: O(n), where n is the length of the string.
*/