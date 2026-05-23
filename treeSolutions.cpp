#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + std::max(maxDepth(root->left),
                                maxDepth(root->right));
        }
    }
};

int main() {
    // Create a simple tree:
    //
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    //

    TreeNode* root = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(4),
            nullptr
        ),
        new TreeNode(3)
    );

    Solution sol;

    std::cout << "Max depth: "
              << sol.maxDepth(root)
              << std::endl;

    return 0;
}