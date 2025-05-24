// leetcode problem : https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();\
        vector<int>res;
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};

/*
Algorithm explanation:
1. Initialize an integer `n` to the size of the `words` vector.
2. Create a vector `res` to store the indices of words containing the character `x`.
3. Loop through each word in the `words` vector using an index `i`.
4. For each word, check if the character `x` is present using the `find` method.
5. If `x` is found in the word (i.e., `find` does not return `string::npos`), append the index `i` to the `res` vector.
6. After the loop, return the `res` vector containing the indices of words that contain the character `x`.
// 7. The time complexity is O(n * m), where n is the number of words and m is the average length of the words.
*/