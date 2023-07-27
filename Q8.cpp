#include <iostream>
#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, int& prev_val, int& min_diff) {
    if (root == nullptr)
        return;

    // Traverse the left subtree
    inorderTraversal(root->left, prev_val, min_diff);

    // Calculate the absolute difference between the current node's value and the previous node's value
    if (prev_val != INT_MAX)
        min_diff = std::min(min_diff, root->val - prev_val);

    // Update the previous node's value with the current node's value
    prev_val = root->val;

    // Traverse the right subtree
    inorderTraversal(root->right, prev_val, min_diff);
}

int getMinimumDifference(TreeNode* root) {
    int prev_val = INT_MAX; // To keep track of the previously visited node's value
    int min_diff = INT_MAX; // To store the minimum absolute difference

    inorderTraversal(root, prev_val, min_diff);

    return min_diff;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int result = getMinimumDifference(root);
    std::cout << "Output: " << result << std::endl; // Output: 1

    // Clean up memory (if needed)
    // Function to delete the tree nodes is not included in this example.
    // You can implement a separate function to delete the tree.

    return 0;
}
