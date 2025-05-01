// leetcode problem : https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/?envType=daily-question&envId=2025-05-01



class Solution {
    public:
        bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
            int pillsUsed = 0;
            multiset<int> st(begin(workers), begin(workers) + mid); 
            for(int i = mid-1; i >= 0; i--) {
                int reqrd = tasks[i];
                auto it   = prev(st.end());
    
                if(*it >= reqrd) {
                    st.erase(it);
                } else if(pillsUsed >= pills) {
                    return false;
                } else {
                    auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                    if(weakestWorkerIt == st.end()) {
                        return false;
                    }
                    st.erase(weakestWorkerIt);
                    pillsUsed++;
                }
            }
            return true;
        }
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            int m = tasks.size();
            int n = workers.size();
            int l = 0;
            int r = min(m, n);
            sort(begin(tasks), end(tasks));
            sort(begin(workers), end(workers), greater<int>());
            int result = 0;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(check(tasks, workers, pills, strength, mid)) {
                    result = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            return result;
        }
    };
    

    /*
    Algorithm Explanation:
    1. Create a function `check` that takes the tasks, workers, pills, strength, and mid as input.
    2. Initialize a variable `pillsUsed` to 0, which will store the number of pills used.
    3. Create a multiset `st` and insert the first `mid` elements from the `workers` vector into it.
    4. Iterate through the `tasks` vector in reverse order from `mid-1` to `0`.
    5. For each task, find the strongest worker using `prev(st.end())` and check if they can complete the task.
    6. If the strongest worker can complete the task, remove them from the multiset.
    7. If the strongest worker cannot complete the task and `pillsUsed` is greater than or equal to `pills`, return false.
    8. If the strongest worker cannot complete the task, find the weakest worker who can complete the task using `st.lower_bound(reqrd - strength)`.
    9. If no such worker exists, return false.
    10. Otherwise, remove the weakest worker from the multiset and increment `pillsUsed` by 1.
    11. After the loop, return true.
    12. Create a function `maxTaskAssign` that takes the tasks, workers, pills, and strength as input.
    13. Initialize variables `m` and `n` to the size of the tasks and workers vectors, respectively.
    14. Initialize variables `l` and `r` to `0` and `min(m, n)` respectively.
    15. Sort the `tasks` vector in ascending order and the `workers` vector in descending order.
    16. Initialize a variable `result` to `0`.
    17. Use a binary search to find the maximum number of tasks that can be assigned.
    18. In each iteration, calculate `mid` as the average of `l` and `r`.
    19. Call the `check` function with the current `mid` value.
    20. If the `check` function returns true, update `result` to `mid` and set `l` to `mid + 1`.
    21. If the `check` function returns false, set `r` to `mid - 1`.
    22. After the loop, return `result` as the maximum number of tasks that can be assigned.
    23. The time complexity of this algorithm is O(n log n), where n is the size of the input arrays, as we are sorting the arrays and performing binary search.
    
    */