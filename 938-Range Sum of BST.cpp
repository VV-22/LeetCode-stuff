/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int lowVar;
    int highVar;
    int rangeSumBST(TreeNode* root, int low, int high) {
        lowVar = low;
        highVar = high;
        TraverseAndAdd(root);
        return sum;
    }
    void TraverseAndAdd(TreeNode* node)
    {
        if(node->val != NULL && node->val >= lowVar && node->val <=highVar)
            sum += node->val;
        if(node->left != nullptr)
            TraverseAndAdd(node->left);
        if(node->right != nullptr)
            TraverseAndAdd(node->right);
    }
};