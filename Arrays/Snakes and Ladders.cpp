https://leetcode.com/problems/snakes-and-ladders/?envType=daily-question&envId=2025-05-31

class Solution {
public:
    int n;
    
    pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        
        que.push(1);
        vector<bool> seen(n*n+1,false);
        
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {
            
                int x = que.front();
                que.pop();

                if(x == n*n)
                    return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push(k+x);
                    else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};


/*
Algorithm Explanation:
1. **Initialization**:
   - The function `snakesAndLadders` initializes the size of the board `n`, a queue `que` for BFS, and a 2D vector `visited` to keep track of visited cells.
   - The starting position (bottom-left corner) is marked as visited.
2. **Coordinate Conversion**:
    - The function `getCoord` converts a linear index to a 2D coordinate on the board, taking into account the zigzag pattern of the board.
3. **BFS Traversal**:
    - The BFS starts from the first cell (1) and explores all possible moves (1 to 6 steps forward).
    - For each move, it checks if the new position is valid and whether it has been visited.
    - If the new position contains a snake or ladder, it jumps to the corresponding cell.
    - If the end of the board (n*n) is reached, it returns the number of steps taken.
4. **Return Value**:
    - If the end of the board is reached, the function returns the number of steps taken. If it is not reachable, it returns -1.    

*/