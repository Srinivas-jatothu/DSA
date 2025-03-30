//leetcode problem : https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30


class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
    
            vector<int> result;
            vector<int> mp(26, -1);
            for(int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                mp[idx] = i;
            }
    
            int i = 0;
            int start = 0;
            int end = 0;
            while(i < n) {
                end = max(end, mp[s[i]-'a']);
                if(i == end) {
                    result.push_back(end-start+1);
                    start = end+1;
                }
                i++;
            }
    
            return result;
        }
    };

    /*
    Algorithm explanation:
    1. Create a vector `mp` of size 26 initialized to -1 to store the last occurrence of each character in the string.
    2. Iterate through the string `s` and update the last occurrence of each character in `mp`.
    3. Initialize `i`, `start`, and `end` to 0.
    4. While `i` is less than the length of the string:
        a. Update `end` to be the maximum of its current value and the last occurrence of the character at index `i` in `mp`.
        b. If `i` is equal to `end`, it means we have found a partition. Push the size of the partition (`end - start + 1`) into the result vector.
        c. Update `start` to be `end + 1` for the next partition.
    5. Increment `i` to move to the next character.
    6. Return the result vector containing the sizes of the partitions.
    */