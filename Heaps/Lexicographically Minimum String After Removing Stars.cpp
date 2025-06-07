//leetcode problem : https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07

class Solution {
public:
    typedef pair<char, int> P;

    struct comp{
        bool operator()(P &p1, P& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        int n = s.length();

        priority_queue<P, vector<P>, comp> pq;

        for(int i = 0; i < n; i++) { 
            if(s[i] != '*') {
                pq.push({s[i], i}); 
            } else {
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        string result = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};


/*
Algorithm Explanation:
1. The `clearStars` function takes a string `s` as input, which may contain characters and stars ('*').
2. It initializes a priority queue `pq` to store pairs of characters and their indices, sorted by character value.
3. It iterates through the string `s`, and for each character:
   - If the character is not a star, it pushes the character and its index into the priority queue.
   - If the character is a star, it pops the top element from the priority queue (which is the lexicographically smallest character) and marks its position in `s` as a star.
4. After processing all characters, it constructs a new string `result` by appending all characters from `s` that are not stars.
5. Finally, it returns the `result` string, which contains the lexicographically smallest string after removing stars.

*/