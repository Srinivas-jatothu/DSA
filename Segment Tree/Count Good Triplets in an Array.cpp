//leetcode problem: https://leetcode.com/problems/count-good-triplets-in-an-array/?envType=daily-question&envId=2025-04-15

class Solution {
    public:
        void updateSegmentTree(int i, int l, int r, int updateIndex, vector<long long>& segmentTree) {
            if (l == r) {
                segmentTree[i] = 1;
                return;
            }    
            int mid = l + (r - l) / 2;
            if (updateIndex <= mid) {
                updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
            } else {
                updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);
            }
    
            segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
        }
    
        long long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, vector<long long>& segmentTree) {
            if (r < queryStart || l > queryEnd) {
                return 0;
            }    
            if (l >= queryStart && r <= queryEnd) {
                return segmentTree[i];
            }    
            int mid = l + (r - l) / 2;
            long long left = querySegmentTree(queryStart, queryEnd, 2 * i + 1, l, mid, segmentTree);
            long long right = querySegmentTree(queryStart, queryEnd, 2 * i + 2, mid + 1, r, segmentTree);
            return left + right;
        }
    
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            unordered_map<int, int> mp;
            for (int i = 0; i < n; i++) {
                mp[nums2[i]] = i;
            }    
            vector<long long> segmentTree(4 * n);  
            long long result = 0;
            updateSegmentTree(0, 0, n - 1, mp[nums1[0]], segmentTree);
            for (int i = 1; i < n; i++) {
                int idx = mp[nums1[i]];
                long long leftCommonCount = querySegmentTree(0, idx, 0, 0, n - 1, segmentTree);
                long long leftNotCommonCount = i - leftCommonCount;
                long long elementsAfterIdxNums2 = (n - 1) - idx;
                long long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
                result += leftCommonCount * rightCommonCount;
    
                updateSegmentTree(0, 0, n - 1, idx, segmentTree);
            }    
            return result;
        }
    };



    /*
    Algorithm explanation:
    1. Create a mapping of nums2 elements to their indices.
    2. Create a segment tree to keep track of the counts of elements in nums1 as we iterate through it.
    3. For each element in nums1, find the index in nums2 using the mapping.
    4. Query the segment tree to get the count of elements in nums1 that are less than the current element's index in nums2.
    5. Calculate the number of good triplets using the counts obtained from the segment tree.
    6. Update the segment tree with the current element's index in nums2.
    7. Return the total count of good triplets.
    */