// leetcode problem : https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

class Solution {
public: 

    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        vector<int> mp(26, 0);
        for(char &ch : s) {
            mp[ch - 'a']++;
        }
        for(int count = 1; count <= t; count++) { 
            vector<int> temp(26, 0);
            for(int i = 0; i < 26; i++) { 
                char ch  = i + 'a'; 
                int freq = mp[i];

                if(ch != 'z') {
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                } else {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }
            mp = move(temp);
        }
        int result = 0;
        for(int i = 0; i < 26; i++) {
            result = (result + mp[i]) % M;
        }
        return result;
    }
};



/*
Algorithm Explanation:
1. Initialize a constant `M` to 1e9 + 7 for modulo operations.
2. Define a function `lengthAfterTransformations` that takes a string `s` and an integer `t`.
3. Get the length of the string `s` and store it in `n`.
4. Create a vector `mp` of size 26 initialized to 0 to store the frequency of each character in the string.
5. Iterate through each character in the string `s` and update the frequency in `mp`.
6. For each transformation from 1 to `t`, create a temporary vector `temp` of size 26 initialized to 0.
7. For each character in the alphabet (0 to 25), calculate the frequency of the next character.
8. If the character is not 'z', update the frequency of the next character in `temp`.
9. If the character is 'z', update the frequencies of 'a' and 'b' in `temp`.
10. After processing all characters, update `mp` with the values from `temp`.
11. Initialize a variable `result` to 0.
12. Iterate through the `mp` vector and sum up the frequencies of all characters.
13. Return the result modulo `M`.
14. The time complexity of this solution is O(t * 26), where `t` is the number of transformations and 26 is the number of characters in the alphabet.
15. The space complexity is O(1) since the size of the frequency vector is constant (26).
*/