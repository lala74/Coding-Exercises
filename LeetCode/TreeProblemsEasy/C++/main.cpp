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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if ((root->left == nullptr) && (root->right == nullptr)) return 1;
        if (root->left == nullptr) return maxDepth(root->right) + 1;
        if (root->right == nullptr) return maxDepth(root->left) + 1;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    TreeNode *left = new TreeNode(15);
    TreeNode *right = new TreeNode(7);
    TreeNode *root = new TreeNode(20, left, right);
    right = root;
    left = new TreeNode(9);
    root = new TreeNode(3, left, right);

    cout << root->val << endl;
    cout << root->left->val << ' ';
    cout << root->right->val << endl;
    cout << root->right->left->val << ' ';
    cout << root->right->right->val<< endl;

    // Main
    Solution solution;
    result = solution.maxDepth(root);

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