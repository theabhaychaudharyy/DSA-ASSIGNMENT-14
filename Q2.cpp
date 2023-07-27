#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long long min_val, long long max_val) {
    if (node == nullptr)
        return true;

    // Check if the current node's value is within the valid range
    if (node->val <= min_val || node->val >= max_val)
        return false;

    // Recursively check left and right subtrees with updated valid ranges
    return isValidBSTHelper(node->left, min_val, node->val) &&
           isValidBSTHelper(node->right, node->val, max_val);
}

bool isValidBST(TreeNode* root) {
    // Start with minimum and maximum possible values (long long to handle edge cases)
    long long min_val = LLONG_MIN;
    long long max_val = LLONG_MAX;

    return isValidBSTHelper(root, min_val, max_val);
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool result = isValidBST(root);
    std::cout << std::boolalpha << "Output: " << result << std::endl; // Output: true

    // Clean up memory (if needed)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
