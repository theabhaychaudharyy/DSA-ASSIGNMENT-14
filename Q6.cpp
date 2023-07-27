#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        // If the root is null, create a new node with the given value.
        return new TreeNode(val);
    }

    if (val < root->val) {
        // If the new value is less than the current node's value,
        // insert it in the left subtree.
        root->left = insertIntoBST(root->left, val);
    } else {
        // If the new value is greater than the current node's value,
        // insert it in the right subtree.
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Helper function to print the BST in inorder traversal
void printBST(TreeNode* root) {
    if (root == nullptr)
        return;

    printBST(root->left);
    std::cout << root->val << " ";
    printBST(root->right);
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    root = insertIntoBST(root, val);

    std::cout << "Output: ";
    printBST(root); // Output: 1 2 3 4 5 7

    // Clean up memory (if needed)
    // Function to delete the tree nodes is not included in this example.
    // You can implement a separate function to delete the tree.

    return 0;
}
