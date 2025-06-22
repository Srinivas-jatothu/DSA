// leetcode problem : https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>res;
        int r=n%k;

        for(int i=0;i<n;i+=k){
            res.push_back(s.substr(i,k));

        }
        if (r != 0) {
            string lastChunk = res.back();
            while (lastChunk.length() < k) {
                lastChunk += fill;  
            }
            res.back() = lastChunk;  
        }

        return res;
        
    }
};


/*
Algorithm Explanation:
1. Initialize an integer `n` to store the length of the input string `s`.
2. Create a vector of strings `res` to store the resulting groups.
3. Calculate the remainder `r` of `n` divided by `k` to determine if the last group needs padding.
4. Iterate through the string `s` in steps of `k`:
   - For each iteration, extract a substring of length `k` starting from index `i` and push it into the `res` vector.   
5. After the loop, check if `r` is not equal to 0, indicating that the last group is shorter than `k`:
   - If so, retrieve the last group from `res` and append the `fill` character until its length reaches `k`.
6. Update the last group in `res` with the padded version.  
7. Finally, return the `res` vector containing the divided groups of size `k`, with the last group padded if necessary.
// Time Complexity: O(n) where n is the length of the input string s, as we iterate through the string once to create the groups.
// Space Complexity: O(n) for storing the resulting groups in the vector `res`.
*/