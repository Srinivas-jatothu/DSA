// leetcode problem : https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05


class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int res=-1;
        for(auto const &[key,value] : mp){
            if(key==value){
                res=max(res,key);
            }
        }

        return res;
    }
};


/*
Algorithm Explanation : 
1. Initialize an unordered map `mp` to store the frequency of each integer in the array.
2. Iterate through the array `arr` and populate the map with the count of each integer.
3. Initialize a variable `res` to -1, which will hold the maximum lucky integer found.
4. Iterate through the map using a range-based for loop to check each key-value pair.
5. If the key (integer) is equal to its value (frequency), it is a lucky integer.
6. Update `res` to be the maximum of its current value and the lucky integer found.
7. Finally, return `res`, which will be the largest lucky integer or -1 if no lucky integer exists.
// Time Complexity: O(n), where n is the size of the input array.   

*/