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
    TreeNode* searchBST(TreeNode* root, int val) {
        bool foundFlag = false;
        TreeNode* current = root; TreeNode* valtoReturn;
        while(!foundFlag)
        {
            if(current -> val < val)
            {
                if(current -> right != nullptr)
                    current = current -> right;
                else
                {
                    valtoReturn = NULL;
                    foundFlag = true;
                }
            }
            else if(current -> val > val)
            {
                if(current -> left != nullptr)
                    current = current -> left;
                else
                {
                    valtoReturn = NULL;
                    foundFlag = true;
                }
            }
            else
            {
                valtoReturn = current;
                foundFlag = true;
            }
        }
        return valtoReturn;
    }
};