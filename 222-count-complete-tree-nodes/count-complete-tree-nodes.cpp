class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            // Left subtree is perfect
            return (1 << leftHeight) + countNodes(root->right);
        } 
        else {
            // Right subtree is perfect
            return (1 << rightHeight) + countNodes(root->left);
        }
    }

    int getHeight(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }
};