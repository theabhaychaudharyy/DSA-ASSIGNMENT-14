#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr)
        return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    std::cout << "Output: " << lca->val << std::endl; // Output: 6

    // Clean up memory (if needed)
    // Function to delete the tree nodes is not included in this example.
    // You can implement a separate function to delete the tree.

    return 0;
}
