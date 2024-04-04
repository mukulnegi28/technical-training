#include <iostream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void preOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    
    cout << root->val << " "; 
    
    preOrder(root->left); 
    preOrder(root->right); 
}


TreeNode* createBinaryTree(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    for (int i = 1; i < arr.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();

        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != -1) {
            current->right = new TreeNode(arr[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}


void deleteBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return;
    
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    
    vector<int> arr = {1, 2, 3, -1, 4, 5, 6, -1, -1, 7, 8};
    
    
    TreeNode* root = createBinaryTree(arr);
    
    
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    
    deleteBinaryTree(root);
    
    return 0;
}