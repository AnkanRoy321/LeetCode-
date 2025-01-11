/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is NULL, there is no ancestor
        if (root == NULL) {
            return NULL;
        }

        // If both p and q are smaller than the current node, search in the left subtree
        if (p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        // If both p and q are larger than the current node, search in the right subtree
        if (p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // If p and q lie on opposite sides of the current node (or one equals the root),
        // then the current node is the LCA
        if (p->val < root->val && q->val > root->val) {
            return root;
        }

        // Symmetric case: if q < root and p > root, current node is also LCA
        if (p->val > root->val && q->val < root->val) {
            return root;
        }

        // Default return, though all cases are handled above
        return root;
    }
};