//leetcode problem : https://leetcode.com/problems/count-days-without-meetings/?envType=daily-question&envId=2025-03-24

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n = meetings.size();
    
            sort(begin(meetings), end(meetings));
    
            int result = 0;
            int start = 0;
            int end = 0;
    
            for(auto &meet : meetings) {
                if(meet[0] > end) {
                    result += meet[0] - end - 1;
                }
    
                end = max(end, meet[1]);
            }
    
            if(days > end) {
                result += days-end;
            }
    
            return result;
        }
    };


    /*
    Algorithm Explanation:
    1. We first sort the meetings based on their start times.
    2. We initialize `result` to count the number of days without meetings, and `start` and `end` to track the current meeting period.
    3. We iterate through the sorted meetings:
        - If the start time of the current meeting is greater than the end time of the last meeting, we add the number of days between them to `result`.
        - We update `end` to be the maximum of its current value and the end time of the current meeting.
    4. After processing all meetings, if there are any days left after the last meeting, we add those to `result`.
    5. Finally, we return the total count of days without meetings.
    */
   