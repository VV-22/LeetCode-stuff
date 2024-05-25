/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution 
{
    public long kthLargestLevelSum(TreeNode root, int k) 
    {
        int arr[k] = {0}, currIndex = 0;
        addValues(root, 0, arr);
        sort(arr, arr + k, greater<int>());
        return arr[k]!=0 ? arr[k] : -1;
    }

    public void addValues(TreeNode root, int currIndex , int[] arr)
    {
        arr[currIndex] += root->val;
        if(root->left != null)
            addValues(root->left, currIndex + 1, arr);
        if(root->right != null)
            addValues(root->right, currIndex + 1 , arr);
        return;
    }
}