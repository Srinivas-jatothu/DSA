// leetcode problem : https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02


class Solution {
    public:
        string pushDominoes(string dominoes) {
            string s = "L" + dominoes + "R";
            int n    = s.length();
            string result = "";
            for(int i = 0, j = 1; j<n; j++) {
                if(s[j] == '.') continue;
                
                int midPartLength = j-i-1;
                if(i > 0)
                    result.push_back(s[i]);
                
                if(s[i] == s[j])
                    result += string(midPartLength, s[i]);
                else if(s[i] == 'L' && s[j] == 'R')
                    result += string(midPartLength, '.');
                else
                    result += string(midPartLength/2, 'R') + string(midPartLength%2, '.') + string(midPartLength/2, 'L');
                i = j;
            }
            
            return result;
        }
    };

    /*
    Algorithm Explanation:
    1. Create a new string `s` by adding 'L' at the beginning and 'R' at the end of the input string `dominoes`.
    2. Initialize an empty string `result` to store the final result.
    3. Iterate through the string `s` using two pointers `i` and `j`, where `i` is the starting index of the current segment and `j` is the current index.
    4. If the character at index `j` is '.', continue to the next iteration.
    5. Calculate the length of the middle part between `i` and `j` as `midPartLength = j - i - 1`.
    6. If `i` is greater than 0, append the character at index `i` to the result.
    7. If the characters at indices `i` and `j` are the same, append `midPartLength` number of that character to the result.
    8. If the character at index `i` is 'L' and the character at index `j` is 'R', append `midPartLength` number of '.' to the result.
    9. Otherwise, append `midPartLength/2` number of 'R', `midPartLength%2` number of '.', and `midPartLength/2` number of 'L' to the result.
    10. Update `i` to `j` for the next iteration.
    11. Finally, return the `result` string.
    12. The time complexity of this algorithm is O(n), where n is the length of the input string `dominoes`.
    */