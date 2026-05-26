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
    /**Super annoying Path Sum III problem wow. Remember to use long long to prevent overflow */
    int countFrom(TreeNode* root, long long target){
        if(root == nullptr){
            return 0;
        }
        if((target - root->val) == 0){
            return 1 + countFrom(root->left,0) + countFrom(root->right,0);
        }else{
            return countFrom(root->left,target - root->val) + countFrom(root->right,target - root->val);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0;
        }
        return countFrom(root, (long long)targetSum) + pathSum(root->left, (long long)targetSum) 
        + pathSum(root->right, (long long)targetSum);
    }
    /**Longest ZigZag Solution best thing to do is keep global variable and dfs  */
    int maxx = 0; 
    void zigZagHelper(TreeNode* root, int direction, int length){
        if(root){
          maxx = std::max(length, maxx);
          if(direction != -1) zigZagHelper(root->left,-1,length+1);
          else zigZagHelper(root->left,-1,1);

          if(direction != 1) zigZagHelper(root->right,1,length+1);
          else zigZagHelper(root->right,1,1);  
        }
        
    }
    int longestZigZag(TreeNode* root) {
        zigZagHelper(root,0,0);
        return maxx;
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