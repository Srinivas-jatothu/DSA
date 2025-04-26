// leetcode problem : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26


class Solution {
public:
string minWindow(string s, string t) {
    int n = s.length();
    map<char, int> mp;
    
    for(char &ch : t) {
        mp[ch]++;
    }
    
    int requiredCount = t.length();
    int i = 0, j  = 0;
    int minStart  = 0;
    int minWindow = INT_MAX;
    while(j < n) {
        char ch_j = s[j];
        if(mp[ch_j] > 0)
            requiredCount--;
        
        mp[ch_j]--;
        
        while(requiredCount == 0) { //try to shrink the window
            if(minWindow > j-i+1) {
                minWindow = j-i+1;
                minStart  = i;
            }
            
            char ch_i = s[i];
            mp[ch_i]++;
            if(mp[ch_i] > 0)
                requiredCount++;
            i++;
        }
        
        j++; //Don't ever forget this :-)
    }
    
    return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
}
};


/*
Algorithm Explanation:
1. Create a function `minWindow` that takes two strings `s` and `t` as input.
2. Initialize `n` to the length of `s`.
3. Create a map `mp` to store the frequency of characters in `t`.
4. Iterate through each character in `t` and increment its count in `mp`.
5. Initialize `requiredCount` to the length of `t`, which represents the number of characters that need to be matched.
6. Initialize two pointers `i` and `j` to 0, which will represent the start and end of the sliding window.
7. Initialize `minStart` to 0 and `minWindow` to `INT_MAX`, which will store the starting index and length of the minimum window found.
8. Use a while loop to iterate through the string `s` with the pointer `j`:
    - If the character at index `j` in `s` is present in `mp`, decrement `requiredCount`.
    - Decrement the count of the character at index `j` in `mp`.
9. Use another while loop to check if `requiredCount` is 0, which means all characters in `t` are matched:
    - If the current window size (`j-i+1`) is smaller than `minWindow`, update `minWindow` and `minStart`.
    - Increment the count of the character at index `i` in `mp`.
    - If the count of the character at index `i` in `mp` becomes greater than 0, increment `requiredCount`.
    - Increment `i` to shrink the window from the left.
10. Increment `j` to expand the window from the right.
11. After the loop, check if `minWindow` is still `INT_MAX`. If it is, return an empty string, indicating no valid window was found.
12. Otherwise, return the substring of `s` starting from `minStart` with length `minWindow`, which represents the minimum window substring containing all characters of `t`.
13. The time complexity of this algorithm is O(n), where n is the length of the string `s`, as we are iterating through the string once and using a hash map for constant time lookups.
*/