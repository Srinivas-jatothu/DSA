// leetcode problem : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        stack<int> st;
        vector<string> vec;
        st.push(groups[0]);
        vec.push_back(words[0]);
        for(int i=1;i<n;i++){
            cout<<"i"<<i<<endl;
            if(st.top()!=groups[i]){
                st.push(groups[i]);
                vec.push_back(words[i]);
            }

        }  
        return vec;
        
    }
};



/*
Algorithm Explanation: 
1. Initialize a stack to keep track of the groups and a vector to store the longest subsequence.
2. Push the first group and the corresponding word into the stack and vector.
3. Iterate through the groups starting from the second group.
4. If the current group is different from the top of the stack, push it into the stack and add the corresponding word to the vector.
5. Return the vector containing the longest subsequence of unequal adjacent groups.
6. The time complexity of this algorithm is O(n), where n is the number of groups, as we are iterating through the groups only once.
*/