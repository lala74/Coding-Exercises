#include <limits.h>
#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        if((root->left == nullptr) && (root->right == nullptr)) return 1;
        if(root->left == nullptr) return maxDepth(root->right) + 1;
        if(root->right == nullptr) return maxDepth(root->left) + 1;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
    //     // 1st solution
    //     bool isValidBST(TreeNode* root)
    //     {
    //         if(root == nullptr) return true;
    //         int minSub = root->val;
    //         int maxSub = root->val;
    //         return is_valid_BST(root, &minSub, &maxSub);
    //     }

    // private:
    //     bool is_valid_BST(TreeNode* root, int* minSub, int* maxSub)
    //     {
    //         if((root->left == nullptr) && (root->right == nullptr)) {
    //             *minSub = root->val;
    //             *maxSub = root->val;
    //             return true;
    //         }
    //         if(root->left == nullptr) {
    //             if(!is_valid_BST(root->right, minSub, maxSub) || (*minSub <= root->val)) {
    //                 return false;
    //             }
    //             *minSub = root->val;
    //             return true;
    //         }
    //         if(root->right == nullptr) {
    //             if(!is_valid_BST(root->left, minSub, maxSub) || (*maxSub >= root->val)) {
    //                 return false;
    //             }
    //             *maxSub = root->val;
    //             return true;
    //         }
    //         int min = 0, max = 0;
    //         if(is_valid_BST(root->left, minSub, maxSub) && (*maxSub < root->val)) {
    //             min = *minSub;
    //         } else {
    //             return false;
    //         }
    //         if(is_valid_BST(root->right, minSub, maxSub) && (*minSub > root->val)) {
    //             max = *maxSub;
    //         } else {
    //             return false;
    //         }
    //         *minSub = min;
    //         *maxSub = max;
    //         return true;
    //     }
    // //  2nd solution
    //     bool isValidBST(TreeNode* root)
    //     {
    //         return is_valid_BST(root, nullptr, nullptr);
    //     }

    // private:
    //     bool is_valid_BST(TreeNode* root, const int* min, const int* max)
    //     {
    //         if(root == nullptr) return true;
    //         if ((min != nullptr) && (root->val <= *min)) {
    //             return false;
    //         }
    //         if((max != nullptr) && (root->val >= *max)) {
    //             return false;
    //         }
    //         return (is_valid_BST(root->left, min, &root->val) && (is_valid_BST(root->right, &root->val, max)));
    //     }
    bool isSymmetric(TreeNode* root) {
        return true;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    TreeNode* left = new TreeNode(15);
    TreeNode* right = new TreeNode(2147483647);
    TreeNode* root = new TreeNode(20, left, right);
    right = root;
    left = new TreeNode(5);
    root = new TreeNode(9, left, right);

    cout << root->val << endl;
    cout << root->left->val << ' ';
    cout << root->right->val << endl;
    cout << root->right->left->val << ' ';
    cout << root->right->right->val << endl;

    // Main
    Solution solution;
    // result = solution.maxDepth(root);
    // result = solution.isValidBST(root);
    result = solution.isSymmetric(root);

    // Output
    cout << result << endl;
    // Runtime
    cout << "------------" << endl;
    printf("Time taken  : %.2f s\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    // Memory usage
    look_up_our_self(&usage);
    printf("Memory usage: %.2f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}