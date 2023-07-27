#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            TreeNode* predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                predecessor->right = curr;
                curr = curr->left;
            } else {
                predecessor->right = nullptr;
                if (prev && prev->val > curr->val) {
                    if (!first) {
                        first = prev;
                        second = curr;
                    } else {
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
        } else {
            if (prev && prev->val > curr->val) {
                if (!first) {
                    first = prev;
                    second = curr;
                } else {
                    second = curr;
                }
            }
            prev = curr;
            curr = curr->right;
        }
    }

    if (first && second) {
        std::swap(first->val, second->val);
    }
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    std::cout << "Before recovery: [";
    std::cout << root->val << "," << root->left->val << ",";
    std::cout << "null,null," << root->left->right->val << "]" << std::endl;

    recoverTree(root);

    std::cout << "After recovery: [";
    std::cout << root->val << "," << root->left->val << ",";
    std::cout << "null,null," << root->left->right->val << "]" << std::endl;

    // Clean up memory (if needed)
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}
