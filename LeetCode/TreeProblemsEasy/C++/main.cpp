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

TreeNode* newNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
    // Base case for recursion
    if(i < n) {
        TreeNode* temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print tree nodes in
// InOrder fashion
void inOrder(TreeNode* root)
{
    if(root != NULL) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
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
    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr) return true;
        return is_symmetric(root->left, root->right);
    }

private:
    bool is_symmetric(TreeNode* left, TreeNode* right)
    {
        if((left == nullptr) && (right == nullptr)) {
            return true;
        } else {
            if(left == nullptr) return false;
            if(right == nullptr) return false;
        }
        if(left->val != right->val) return false;
        return (is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left));
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    int result;

    // Input
    int arr[] = {1, 2, 2, NULL, 3, NULL, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = nullptr;
    root = insertLevelOrder(arr, root, 0, n);
    inOrder(root);
    cout << '\n';

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