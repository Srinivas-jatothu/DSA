//leetcode problem : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n = intervals.size();
            sort(begin(intervals), end(intervals));
            vector<vector<int>> result;
            result.push_back(intervals[0]);
            for(int i = 1; i < n; i++) {
                if(intervals[i][0] < result.back()[1]) { 
                    result.back()[1] = max(result.back()[1], intervals[i][1]);
                } else {
                    result.push_back(intervals[i]);
                }
            }
    
            return result;
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>>hor;
            vector<vector<int>>ver;
            for(int i=0;i<rectangles.size();i++){
                hor.push_back({rectangles[i][0], rectangles[i][2]});
                ver.push_back({rectangles[i][1], rectangles[i][3]});
            }
           
            vector<vector<int>>res_h=merge(hor);
            cout<<res_h.size();
            if(res_h.size()>=3){
                return true;
            }
            vector<vector<int>>res_v=merge(ver);
            if(res_v.size()>=3){
                return true;
            }
            return false;
        }
    };


    /*
    Algorithm Explanation:
    1. We first sort the rectangles based on their start and end points.
    2. We initialize two vectors `hor` and `ver` to store the horizontal and vertical intervals of the rectangles.
    3. We iterate through the rectangles and push their horizontal and vertical intervals into `hor` and `ver` respectively.
    4. We then call the `merge` function to merge overlapping intervals in both `hor` and `ver`.
    5. If the size of the merged horizontal intervals is greater than or equal to 3, we return true.
    6. If the size of the merged vertical intervals is greater than or equal to 3, we also return true.
    7. If neither condition is met, we return false.
    8. The `merge` function merges overlapping intervals and returns the merged intervals.
    9. The merging process involves iterating through the sorted intervals and checking if the start of the current interval is less than the end of the last merged interval.
    10. If they overlap, we update the end of the last merged interval to be the maximum of its current value and the end of the current interval.
    11. If they do not overlap, we add the current interval to the merged intervals.
    12. Finally, we return the merged intervals.
    13. The time complexity of this algorithm is O(n log n) due to the sorting step, and the space complexity is O(n) for storing the merged intervals.
    */