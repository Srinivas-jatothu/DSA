// leetcode problem : https://leetcode.com/problems/shifting-letters/description/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n= shifts.size();
        vector<int>prefixsum(n);
        prefixsum[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            prefixsum[i]=(shifts[i]+prefixsum[i+1])%26;
        }

        for(int i=0;i<n;i++){
            int shift=prefixsum[i];
            s[i]='a'+(s[i]-'a'+shift)%26;
        }

        return s;
        
    }
};


       

/*
Algorithm Explanation:
1. Initialize a vector `prefixsum` to store the cumulative shifts.
2. Calculate the cumulative shifts in reverse order, starting from the last element of `shifts`.
3. For each character in the string `s`, apply the corresponding cumulative shift from `prefixsum`.
4. Convert the character to its new value by adding the shift and wrapping around using modulo 26. we are using %26 to ensure that the shift wraps around the alphabet.
5. Return the modified string `s` after applying all shifts.
// Time Complexity: O(n), where n is the length of the string `s`.
// Space Complexity: O(n), for the `prefixsum` vector.
*/