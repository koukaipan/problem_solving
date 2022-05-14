/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode* node = root;
    
    while(node) {
        if (val < node->val)
            node = node->left;
        else if (val > node->val)
            node = node->right;
        else
            return node;
    }
    
    return node;
}
