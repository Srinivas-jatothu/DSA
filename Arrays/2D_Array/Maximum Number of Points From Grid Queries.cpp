//leetcode problem : https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/submissions/1589034774/?envType=daily-question&envId=2025-03-28

class Solution {
    public:
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size();
            int n = grid[0].size();
    
            int Q = queries.size();
            vector<int> result(Q, 0);
    
            vector<pair<int, int>> sortedQ;
            for(int i = 0; i < Q; i++) {
                sortedQ.push_back({queries[i], i});
            }
    
            sort(begin(sortedQ), end(sortedQ));
    
            priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;  // min-heap which store {value, i, j}
            vector<vector<bool>> visited(m, vector<bool>(n, false));  //this is to check if the cell is visited or not
            int points = 0;
            pq.push({grid[0][0], 0, 0});
            visited[0][0] = true;
    
    
            for(int i = 0; i < Q; i++) {
                int queryValue = sortedQ[i].first;
                int idx        = sortedQ[i].second;
                while(!pq.empty() && pq.top()[0] < queryValue) {
                    int i = pq.top()[1];
                    int j = pq.top()[2];
                    pq.pop();
                    points++;
    
                    for(auto &dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                            pq.push({grid[i_][j_], i_, j_});
                            visited[i_][j_] = true;
                        }
                    }
                }
                result[idx] = points;
            }
            
            return result;
        }
    };





/*
Algorithm Explanation:
1. We first create a vector `sortedQ` to store the queries along with their original indices.
2. We sort the queries in ascending order based on their values.
3. We initialize a priority queue `pq` to store the grid cells based on their values.
4. We also create a 2D vector `visited` to keep track of the cells that have been visited.
5. We start from the top-left cell of the grid and push it into the priority queue.
6. We mark the top-left cell as visited.
7. We initialize a variable `points` to keep track of the number of points we can collect.
8. For each query, we check if the top element of the priority queue is less than the query value.
9. If it is, we pop the top element from the priority queue and increment the `points` variable.
10. We then check the four possible directions (up, down, left, right) from the current cell.
11. If the neighboring cell is within bounds and has not been visited, we push it into the priority queue and mark it as visited.
12. We repeat this process until the top element of the priority queue is greater than or equal to the query value.
13. We store the current number of points in the result vector at the index corresponding to the original index of the query.
14. Finally, we return the result vector containing the maximum number of points for each query.

*/