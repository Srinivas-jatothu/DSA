// leetcode problem : http://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06



class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int &x : vec2) {
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int &x : vec1) {
            c += mp[tot-x];
        }

        return c;
    }
};


/*
Algorithm Explanation:
1. The `FindSumPairs` class is initialized with two vectors, `nums1` and `nums2`.
2. The constructor stores `nums1` in `vec1` and `nums2` in `vec2`, and creates a frequency map `mp` for elements in `vec2`.
3. The `add` method updates the value at a specific index in `vec2` and adjusts the frequency map accordingly.
4. The `count` method counts how many pairs of elements from `vec1` and `vec2` sum up to a given total. It iterates through `vec1` and uses the frequency map to find how many elements in `vec2` can form the required sum with each element in `vec1`.
// Time Complexity: O(n) for initialization, O(1) for `add`, and O(m) for `count`, where n is the size of `nums2` and m is the size of `nums1`.
// Space Complexity: O(n) for storing the frequency map.
*/