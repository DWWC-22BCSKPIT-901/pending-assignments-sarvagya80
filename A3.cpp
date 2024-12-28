#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int left, int right, unordered_map<int, int>& inorderMap) {
    if (left > right) return nullptr;

    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    root->left = buildTreeHelper(preorder, inorder, preorderIndex, left, inorderMap[rootVal] - 1, inorderMap);
    root->right = buildTreeHelper(preorder, inorder, preorderIndex, inorderMap[rootVal] + 1, right, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
}

// Example usage
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);
    cout << "Tree constructed successfully!" << endl;

    return 0;
}
