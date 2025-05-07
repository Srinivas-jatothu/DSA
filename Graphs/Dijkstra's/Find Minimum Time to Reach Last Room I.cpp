// leetcode problem : https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/?envType=daily-question&envId=2025-05-07



class Solution {
    public:
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        //{t, {i, j}}
        typedef pair<int, pair<int, int>> P;
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
    
            vector<vector<int>> result(m, vector<int>(n, INT_MAX));
            priority_queue<P, vector<P>, greater<P>> pq;
    
            result[0][0] = 0;
            pq.push({0, {0, 0}});
            while(!pq.empty()) { 
                int currTime = pq.top().first;
                auto cell     = pq.top().second;
                int i = cell.first;
                int j = cell.second;
    
                pq.pop();
                if(i == m-1 && j == n-1) {
                    return currTime;
                }
    
                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
    
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                        int wait    = max(moveTime[i_][j_] - currTime, 0);
                        int arrTime = currTime + wait + 1;
    
                        if(result[i_][j_] > arrTime) {
                            result[i_][j_] = arrTime;
                            pq.push({arrTime, {i_, j_}});
                        }
                        
                    }
                }
            }
    
            return -1;
    
        }
    };


    /*
    Algorithm Explanation:
    1. The function `minTimeToReach` takes a 2D vector `moveTime` as input, representing the time required to move from each cell to its adjacent cells.
    2. It initializes the dimensions of the grid `m` and `n`.
    3. It creates a 2D vector `result` to store the minimum time to reach each cell, initialized to `INT_MAX`.
    4. It creates a priority queue `pq` to perform Dijkstra's algorithm, where each element is a pair of the current time and the coordinates of the cell.
    5. The starting cell (0, 0) is initialized with a time of 0 and pushed into the priority queue.
    6. The algorithm enters a loop that continues until the priority queue is empty.
    7. It pops the cell with the smallest time from the priority queue.
    8. If the current cell is the bottom-right cell (m-1, n-1), it returns the current time as the minimum time to reach the last room.
    9. It iterates through the four possible directions (up, down, left, right) to explore adjacent cells.
    10. For each adjacent cell, it checks if the new coordinates are within bounds.
    11. It calculates the wait time based on the move time of the adjacent cell and the current time.
    12. It calculates the arrival time by adding the wait time and 1 (for the move).
    13. If the arrival time is less than the recorded time for that cell, it updates the result and pushes the new time and coordinates into the priority queue.
    14. Finally, if the priority queue is empty and the last room has not been reached, it returns -1.
    15. The time complexity of this algorithm is O(m * n * log(m * n)), where m and n are the dimensions of the grid, as it processes each cell once and uses a priority queue for efficient retrieval of the minimum time.
    */