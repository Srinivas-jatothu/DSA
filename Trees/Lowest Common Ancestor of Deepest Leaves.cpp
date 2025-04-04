
// LeetCode problem : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2025-04-04




class Solution {
    public:
        pair<int, TreeNode*> solve(TreeNode* root) {
            if(root == NULL) {
                return {0, NULL};
            }
    
            auto l = solve(root->left);
            auto r = solve(root->right);
    
            if(l.first == r.first) {
                return {l.first+1, root};
            } else if(l.first > r.first) {
                return {l.first+1, l.second};
            } else {
                return {r.first+1, r.second};
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return solve(root).second;   
        }
    };


    /*
    Algorithm explanation:
    1. The function `lcaDeepestLeaves` is designed to find the lowest common ancestor (LCA) of the deepest leaves in a binary tree.
    2. It uses a helper function `solve` that returns a pair:
        - The first element of the pair is the depth of the deepest leaves.
        - The second element is the node that is the LCA of those deepest leaves.
    3. The `solve` function works recursively:
        - If the current node is `NULL`, it returns a depth of `0` and a `NULL` node.
        - It recursively calls itself for the left and right children of the current node.
        - If both left and right depths are equal, it means the current node is the LCA of the deepest leaves.
        - If one side is deeper, it returns the deeper side's depth and LCA.
    4. The main function `lcaDeepestLeaves` simply calls the `solve` function and returns the second element of the pair, which is the LCA of the deepest leaves.
    

    */