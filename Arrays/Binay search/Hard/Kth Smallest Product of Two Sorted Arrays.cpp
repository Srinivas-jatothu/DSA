// leetcode problem : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/?envType=daily-question&envId=2025-06-25

class Solution {
public:

    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productsCount = 0;

        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {

            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; 

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                productsCount += (m+1); 
            } else {
                
                int l = 0;
                int r = n-1;
                int m = n; 

                while(l <= r) {
                    int mid = l + (r-l)/2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                                                    
                productsCount += (n - m);
            }
        }
        return productsCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long l = -1e10;
        long long r = 1e10; 

        while(l <= r) {
            long long midProduct = l + (r-l)/2;


            long long countSmallest = findCountSmallest(nums1, nums2, midProduct);

            if(countSmallest >= k) {
                result = midProduct;
                r = midProduct-1;
            } else {
                l = midProduct+1;
            }
        }
        return result;
    }
};


/*
Algorithm Explanation:
1. The function `findCountSmallest` counts how many products of pairs from `nums1` and `nums2` are less than or equal to `midProduct`.
   - It iterates through each element of `nums1`.
   - For non-negative elements, it performs a binary search on `nums2` to find how many products are less than or equal to `midProduct`.
   - For negative elements, it does a similar binary search but counts products that are greater than or equal to `midProduct`.
2. The function `kthSmallestProduct` uses binary search to find the k-th smallest product.
   - It initializes the search range from `-1e10` to `1e10`.
   - It calculates the mid-point and uses `findCountSmallest` to count how many products are less than or equal to `midProduct`.
   - If the count is greater than or equal to `k`, it updates the result and narrows the search range to the left half (to find smaller products).
3. The process continues until the search range is exhausted, and the function returns the k-th smallest product found.
4. The time complexity is O(n log m), where n is the size of `nums1` and m is the size of `nums2`, due to the binary search for each element in `nums1`.
5. The space complexity is O(1) as no additional data structures are used that grow with input size.
*/