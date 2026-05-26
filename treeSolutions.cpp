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
    /**Max Depth of a binary tree */
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + std::max(maxDepth(root->left),
                                maxDepth(root->right));
        }
    }
    /**Determining if two binary trees are leaf similar*/
    void getLeaves(TreeNode* root, std::vector<int>& leaves) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        }

        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1;
        std::vector<int> leaves2;

        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return leaves1 == leaves2;
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