// leetcode problem : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        int day = events[0][0]; //5
        int i   = 0;
        int count = 0; //result number of events attended

        while(!pq.empty() || i < n) {
            
            if(pq.empty()) {
                day = events[i][0];
            }

            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) {
                pq.pop(); //1 event attended on this day
                count++; //counting the result
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};



/*
Algorithm Explanation:
1. The `maxEvents` function takes a vector of events, where each event is represented as a vector with start and end days.
2. It sorts the events based on their start days.
3. A min-heap (priority queue) is used to keep track of the end days of the events that can be attended.
4. The algorithm iterates through the days, adding events that start on the current day to the min-heap.
5. If the min-heap is not empty, it pops the earliest ending event, indicating that one event is attended on that day.
6. The day is incremented, and any events that have already ended (i.e., their end day is less than the current day) are removed from the min-heap.
7. The process continues until all events are processed, and the total count of attended events is returned.
// Time Complexity: O(n log n) for sorting the events and O(n log n) for processing the events using the priority queue, where n is the number of events.
// Space Complexity: O(n) for the priority queue used to store the end days of events.
*/