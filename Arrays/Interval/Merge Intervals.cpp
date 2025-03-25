//leetcode problem : https://leetcode.com/problems/merge-intervals/description/

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n=intervals.size();
            sort(begin(intervals),end(intervals));
            vector<vector<int>>res;
            res.push_back(intervals[0]);
            for(int i=1;i<n;i++){
                int start=intervals[i][0];
                int end=intervals[i][1];
                if(start>res.back()[1]){
                    res.push_back(intervals[i]);
                }
                else{
                    res.back()[1]=max(res.back()[1],end);
                }
            }
            return res;
        }
    };


    /*
    Algorithm Explanation:
    1. We first sort the intervals based on their start times.
    2. We initialize a result vector `res` and add the first interval to it.
    3. We iterate through the sorted intervals:
        - If the start time of the current interval is greater than the end time of the last interval in `res`, we add the current interval to `res`.
        - Otherwise, we merge the current interval with the last interval in `res` by updating its end time to be the maximum of its current value and the end time of the current interval.
    4. Finally, we return the merged intervals stored in `res`.
    */