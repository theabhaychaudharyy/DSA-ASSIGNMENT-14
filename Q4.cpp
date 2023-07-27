#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBSTHelper(const std::vector<int>& nums, int left, int right) {
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

void printBST(TreeNode* root) {
    if (root == nullptr)
        return;

    printBST(root->left);
    std::cout << root->val << " ";
    printBST(root->right);
}

int main() {
    // Example usage:
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(nums);

    std::cout << "Output: ";
    printBST(root); // Output: -10 -3 0 5 9

    // Clean up memory (if needed)
    // Function to delete the tree nodes is not included in this example.
    // You can implement a separate function to delete the tree.

    return 0;
}
